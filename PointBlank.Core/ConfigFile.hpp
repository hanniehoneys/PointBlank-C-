#pragma once
#include <cstdint>
#include <fstream>
#include <sstream>
#include <rapidjson/document.h>

class ConfigFile {
public:
    static void Parse(const std::string& filePath, rapidjson::Document* document) {
        std::ifstream ifs(filePath);
        if (!ifs.is_open()) 
            throw std::runtime_error(std::format("Failed to open file {}", filePath));

        std::string fileContent((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
        ifs.close();

        if (document->Parse(fileContent.c_str()).HasParseError())
            throw std::runtime_error(std::format("Failed to parse JSON data (file: {})", filePath));
    }
};