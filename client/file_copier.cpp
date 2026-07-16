#include <iostream>
#include <filesystem>
#include <fstream>
#include "file_copier.h"
namespace fs = std::filesystem;

const static int BUFFER_SIZE = 4096;


bool copyFile(const fs::path& source, const fs::path& destination){
    std::ifstream input;
    input.open(source);

    if(input.is_open() == false){
        std::cout << "error opening file" << std::endl;
        return false;
    }

    std::ofstream output;

    
 
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

    return true;

}