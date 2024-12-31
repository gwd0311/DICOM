//
//  DocumentPickerImportView.swift
//  Dicom
//
//  Created by hanjongwoo on 12/31/24.
//

import SwiftUI
import UniformTypeIdentifiers

import SwiftUI
import UniformTypeIdentifiers

// 문서 선택기를 구현하는 뷰
struct DocumentPickerImportView: UIViewControllerRepresentable {
    @Binding var path: URL       // 선택된 파일의 경로
    @Binding var loading: Bool   // 파일이 로딩 중일 때 true로 설정
    @Binding var data: DicomData // 로드된 데이터
    
    // 코디네이터를 생성하여, 파일 선택 후 작업을 담당
    func makeCoordinator() -> DocumentPickerCoordinator {
        return DocumentPickerCoordinator(path: $path, loading: $loading, data: $data)
    }
    
    // UIDocumentPickerViewController를 생성
    func makeUIViewController(context: UIViewControllerRepresentableContext<DocumentPickerImportView>) -> UIDocumentPickerViewController {
        let documentPicker = UIDocumentPickerViewController(forOpeningContentTypes: [UTType.item], asCopy: false)
        documentPicker.delegate = context.coordinator
        return documentPicker
    }

    func updateUIViewController(_ uiViewController: UIDocumentPickerViewController, context: Context) {
    }
}
