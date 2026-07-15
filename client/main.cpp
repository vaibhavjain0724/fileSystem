
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
namespace fs = std::filesystem;



fs::path filePathRead(const std::string &path){
    fs::path filePath(path);

    return filePath;
}

bool filePathExists(fs::path& filePath){

    return fs::exists(filePath);
}

void tempPrint(fs::path& filePath){
    std::ifstream input;


    input.open(filePath);

    if(input.is_open() != true){
        std::cout << "error opening file " << std::endl;
        return;
    }
    int lineNumber = 0;
    while(std::getline(filePath, lineNumber)){
        std::cout << lineNumber << ": ";
        std::cout << std::getline(filePath, lineNumber) << std::endl;
    }

    input.close();
}

bool Upload(fs::path& filePath){
    //
    return false;
}

int main(int argc , char* argv[]){
    
    if(argc != 2){
        std::cout << "format: 'file path'" << std::endl;
        return -1;
    }

    //store path in filePath
    fs::path filePath;
    filePath = filePathRead(argv[1]);

    //check if valid
    bool validPath;
    validPath = filePathExists(filePath);

    if(validPath == false){
        std::cout << "Invalid File Path" << std::endl;
        return -1;
    }

    std::cout << filePath << std::endl;

    //
    tempPrint(filePath);

    //Upload
    Upload(filePath);
}

