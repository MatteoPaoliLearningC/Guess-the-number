#include <map>
#include <fstream>
#include <string>
#include <stdexcept>

const std::string CONFIG_FILE_NAME = "settings.cfg";

std::map<std::string, int> get_settings() {
  std::ifstream settingsFile(CONFIG_FILE_NAME);
  std::map<std::string, int> settings;
  if (settingsFile.is_open()) {
    std::string line;
    while (std::getline(settingsFile, line)) {
      size_t pos = line.find('=');
      if (pos != std::string::npos) {
        std::string key = line.substr(0, pos);
        int value = std::stoi(line.substr(pos + 1));
        settings[key] = value;
      }
    }
    return settings;
  } else {
    throw std::runtime_error("Failed to open the file.");
  }
}