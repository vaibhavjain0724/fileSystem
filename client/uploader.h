#pragma once

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void uploadFile(const fs::path& path);