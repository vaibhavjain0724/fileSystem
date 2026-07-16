#include "uploader.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>


namespace fs = std::filesystem;

const static int BUFFER_SIZE = 4096;

void uploadFile(const fs::path& path,const std::string& newFileName){
    std::ifstream input;
    input.open(path);

    if(input.is_open() == false){
        std::cout << "error opening file" << std::endl;
        return;
    }

    std::ofstream output;

    fs::path storageDirectory("./server_data/storage");

    fs::path fileName(newFileName);

    fs::path destination = storageDirectory / fileName;

    output.open(destination);


    //!old line by line copying logic
    // std::string line;

    // while(std::getline(input, line)){
    //     output << line << std::endl;

    // }

    char buffer[BUFFER_SIZE];
    input.read(buffer, BUFFER_SIZE);
    while(input.gcount()){
        output.write(buffer, input.gcount());
        input.read(buffer, BUFFER_SIZE);

    }

    input.close();



}