#pragma once

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void downloadFile(const fs::path& path);