#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int parseAllFromPath(std::string path){
    //std::string path = "./assets/models/";
    std::cout << "Parsing objects from " << path << ":" << std::endl;
    for (const auto & entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
    }
    std::cout << "Done parsing objects." << std::endl;
}

int parseObject(std::string path){
    std::cout << "Parsing object: " << path << std::endl;
}