#pragma once
#include <string>
#include <ctime>
#include <cpprest/http_client.h>

class JSONParser {
    std::string file;

public:
    JSONParser(std::string file) : file{ file } {};
    std::string getRandomImageUrl();
    bool emptyJSON();
};

