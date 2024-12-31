//
//  ContentView.swift
//  Dicom
//
//  Created by hanjongwoo on 12/31/24.
//

import SwiftUI

struct ContentView: View {
    @State var showFilePicker: Bool = false // 파일 선택기 표시 여부
    @State var path: URL = URL(fileURLWithPath: "") // 선택된 파일 경로
    @State var loading = false // 로딩 상태
    @State var data = DicomData(image: nil) // 로드된 데이터

    var body: some View {
        VStack {
            // 파일 로드 버튼
            Button(action: {
                self.showFilePicker.toggle()
            }) {
                Label("Load dataset", systemImage: "doc.text.image").frame(maxWidth: .infinity)
            }
            .buttonStyle(.bordered).padding([.leading, .trailing])
            .disabled(loading)
            
            // 환자 이름 표시
            Text(data.patientName)
            
            // 이미지 표시
            if data.image != nil {
                Image(uiImage: data.image!).resizable()
                    .scaledToFit().imageScale(.medium)
            }
        }
        .padding()
        .sheet(isPresented: self.$showFilePicker) {
            DocumentPickerImportView(path: $path, loading: $loading, data: $data)
        }
    }
}

#Preview {
    ContentView()
}
