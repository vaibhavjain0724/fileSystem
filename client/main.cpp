#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "uploader.h"
#include "downloader.h"
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
    std::string line;

    while(std::getline(input, line)){
        std::cout << lineNumber << ": " << line << std::endl;
        lineNumber++;

    }

    input.close();
}

// int main(int argc , char* argv[]){
    
//     if(argc != 2){
//         std::cout << "format: 'file path'" << std::endl;
//         return -1;
//     }

//     //store path in filePath
//     fs::path filePath;
//     filePath = filePathRead(argv[1]);

//     //check if valid
//     bool validPath;
//     validPath = filePathExists(filePath);

//     if(validPath == false){
//         std::cout << "Invalid File Path" << std::endl;
//         return -1;
//     }

//     std::cout << filePath << std::endl;

//     //
//     // tempPrint(filePath);

//     //Upload
//     // std::string newFileName = argv[2];
//     uploadFile(filePath);
// }


int main(int argc, char* argv[]){
    if(argc < 2){
        std::cout << "Download 'file name' / Upload 'path' / View" << std::endl;
    }

    std::string command = argv[1];

    if(command == "Upload" || command == "upload"){
        //store path in filePath
        fs::path filePath;
        filePath = filePathRead(argv[2]);

        //check if valid
        bool validPath;
        validPath = filePathExists(filePath);

        if(validPath == false){
            std::cout << "Invalid File Path" << std::endl;
            return -1;
        }

        uploadFile(filePath);
    }
    
    else if(command == "Download" || command == "download"){
        fs::path filePath;
        filePath = filePathRead(argv[2]);
        downloadFile(filePath);
    }
    else if(command == "View" || command == "view"){

    }
    else{
         std::cout << "Download / Upload / View" << std::endl;
    }
    
}