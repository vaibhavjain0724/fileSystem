#include "downloader.h"
#include "file_copier.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void downloadFile(const fs::path& path)
{
    // report.pdf
    fs::path fileName = path.filename();

    // server_data/storage/report.pdf
    fs::path storageDirectory("./server_data/storage");
    fs::path source = storageDirectory / fileName;

    // ./report.pdf (current working directory)
    fs::path currentDirectory(".");
    fs::path destination = currentDirectory / fileName;

    if (copyFile(source, destination))
    {
        std::cout << "Download Successful" << std::endl;
    }
    else
    {
        std::cout << "Download Failed" << std::endl;
    }
}