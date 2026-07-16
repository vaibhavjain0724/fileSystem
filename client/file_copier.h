#pragma once

#include <filesystem>

namespace fs = std::filesystem;

bool copyFile(const fs::path& source,
              const fs::path& destination);