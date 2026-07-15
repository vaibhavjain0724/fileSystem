#include "uploader.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

void uploadFile(const fs::path& path,const std::string& newFileName){
    std::ifstream input;
    input.open(path);

    if(input.is_open() == false){
        std::cout << "error opening file" << std::endl;
        return;
    }

    std::ofstream output;

    output.open("./server_data/storage/" + newFileName);

    std::string line;

    while(std::getline(input, line)){
        output << line << std::endl;

    }

    input.close();



}