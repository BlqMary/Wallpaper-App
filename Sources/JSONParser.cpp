#include "JSONParser.h"

using namespace utility;
using namespace web;
using namespace utility::conversions;

bool JSONParser::emptyJSON() {
    stringstream_t stream;
    json::value value;
    ifstream_t f(this->file);
    try {
        if (f) {
            stream << f.rdbuf();
            f.close();

            json::value obj = json::value::parse(stream);
            int hitsNumber = obj.at(U("totalHits")).as_integer();
            return hitsNumber == 0;
        }
    }
    catch (web::json::json_exception excep) {
        std::cout << "ERROR Parsing JSON: ";
        std::cout << excep.what();
        return false;
    }
}

std::string JSONParser::getRandomImageUrl() {
    string_t imageURL;
    stringstream_t stream;
    ifstream_t f(this->file);

    
    try {
        if (f) {
            stream << f.rdbuf();
            f.close();

            json::value obj = json::value::parse(stream);
            auto hits = obj.at(U("hits")).as_array();
            int len = hits.size();

            std::srand(std::time(nullptr));
            auto randHit = hits.at(rand() % len);

            imageURL = randHit.at(U("largeImageURL")).as_string();
            std::string url = utility::conversions::to_utf8string(imageURL);
            return url;
        }
    }
    catch (web::json::json_exception excep) {
        std::cout << "ERROR Parsing JSON: ";
        std::cout << excep.what();
        return "";
    }
}

