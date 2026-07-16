#include "list_files.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void listFiles(){
    fs::path storageDirectory("./server_data/storage");

    if (!fs::exists(storageDirectory)){
        std::cout << "Storage directory does not exist." << std::endl;
        return;
    }

    std::cout << "Stored Files:\n" << std::endl;

    bool empty = true;

    for (const auto& entry : fs::directory_iterator(storageDirectory))
    {
        if (entry.is_regular_file())
        {
            std::cout << entry.path().filename() << std::endl;
            empty = false;
        }
    }

    if (empty)
    {
        std::cout << "No files uploaded." << std::endl;
    }
}


