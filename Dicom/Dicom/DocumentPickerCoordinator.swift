//
//  DocumentPickerCoordinator.swift
//  Dicom
//
//  Created by hanjongwoo on 12/31/24.
//

import SwiftUI

// UIDocumentPickerDelegate와 UINavigationControllerDelegate를 구현하는 코디네이터
class DocumentPickerCoordinator: NSObject, UIDocumentPickerDelegate, UINavigationControllerDelegate {
    @Binding var path: URL       // 선택된 파일의 경로
    @Binding var loading: Bool   // 파일 로딩 중 상태
    @Binding var data: DicomData // 로드된 DICOM 데이터

    init(path: Binding<URL>, loading: Binding<Bool>, data: Binding<DicomData>) {
        self._path = path
        self._loading = loading
        self._data = data
    }

    // 파일을 선택한 후 호출되는 메소드
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        // 파일이 선택되지 않았다면 작업을 중지합니다.
        guard !urls.isEmpty else {
            DispatchQueue.main.async {
                self.loading = false // 로딩 상태를 해제
            }
            return
        }
        
        path = urls[0]
        // 백그라운드 스레드에서 파일을 로드
        DispatchQueue.global(qos: .background).async {
            self.loadImage(url: urls[0])
        }
    }

    // 취소된 경우 호출되는 메소드
    func documentPickerWasCancelled(_ controller: UIDocumentPickerViewController) {
        DispatchQueue.main.async {
            self.loading = false // 로딩 상태를 해제
        }
    }

    // 파일을 로드하는 메소드
    private func loadImage(url: URL) {
        // 로딩 중임을 알림
        DispatchQueue.main.async {
            self.loading = true
        }
        
        guard url.startAccessingSecurityScopedResource() else {
            return
        }
        
        defer {
            DispatchQueue.main.async {
                self.loading = false
            }
            url.stopAccessingSecurityScopedResource()
        }
        
        do {
            // DICOMHero의 기본 메모리 할당 제한을 설정하여 메모리 과다 할당 방지
            DicomheroCodecFactory.setMaximumImageSize(8000, maxHeight: 8000)
            // 선택된 파일에서 DICOM 데이터셋 로드
            let dataset: DicomheroDataSet = try DicomheroCodecFactory.load(fromFileMaxSize: url.path, maxBufferSize: 2048)
            // 변환을 적용한 이미지를 가져옴
            let heroImage: DicomheroImage = try dataset.getImageApplyModalityTransform(0)

            // 이미지 크기 가져오기
            let width = heroImage.width
            let height = heroImage.height
            // 이미지 변환 체인을 구성
            let chain = DicomheroTransformsChain()

            // 모노크롬 이미지일 경우 VOI 정보로 변환
            // VOI: DICOM 이미지에서 특정 부분을 조정하는 메타데이터
            // 특정 밝기나 대비를 강조: ex) CT 스캔에서는 뼈, 근육, 혈관 등을 구분하기위해 다른 VOI 설정
            /// VOI 관련 데이터
            /// LUT(Look-Up Table): 픽셀 값에 대한 변환 테이블, VOI에 따라 이미지를 색상이나 밝기수준으로 조정할지 정의
            /// WW(Window Width): 이미지의 밝기 범위
            /// WL(Window Level): 이미지의 중앙 밝기
            if DicomheroColorTransformsFactory.isMonochrome(heroImage.colorSpace) {
                let vois = try dataset.getVOIs() as! Array<DicomheroVOIDescription>
                if !vois.isEmpty {
                    chain!.add(DicomheroVOILUT(voiDescription: vois.first))
                } else {
                    let voiDescription = try DicomheroVOILUT.getOptimalVOI(heroImage, inputTopLeftX: 0, inputTopLeftY: 0, inputWidth: width, inputHeight: height)
                    chain!.add(DicomheroVOILUT(voiDescription: voiDescription))
                }
            }

            // 변환된 이미지를 얻기 위한 그리기 객체 생성
            let draw = DicomheroDrawBitmap(transform: chain)
            let image = try draw?.getDicomheroImage(heroImage)

            // 환자 이름 가져오기
            var patientName = ""
            do {
                let patientNameStructure = try dataset.getPersonName(DicomheroTagId(id: DicomheroTagEnum.enumPatientName_0010_0010), elementNumber: 0)
                patientName = (patientNameStructure?.alphabeticRepresentation)!
            } catch {
                print("caught: \(error)")
            }

            // 메인 스레드에서 데이터를 업데이트
            DispatchQueue.main.async {
                self.data.image = image
                self.data.patientName = patientName
            }
        } catch {
            print("caught: \(error)")
        }
    }
}
