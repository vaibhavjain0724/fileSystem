#include "uploader.h"
#include <filesystem>
#include "file_copier.h"
#include <iostream>

namespace fs = std::filesystem;


void uploadFile(const fs::path& path){
    fs::path newFileName = path.filename();
    fs::path storageDirectory("./server_data/storage");
    fs::path destination = storageDirectory / newFileName;

    if(copyFile(path , destination )){
        std::cout << "Success" << std::endl;
    }
    else  std::cout << "Failed" << std::endl;



}