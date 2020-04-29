#pragma once

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <string>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;
using namespace utility::conversions;


class APIController {
    std::shared_ptr<ostream> fileStream;
    const string_t key = to_string_t("16023779-0de0e9c29d6126c42232e343d");
public:
    APIController();
    ~APIController() = default;

    pplx::task<void> getPhotos(std::string resultFile, std::string searchTerm, std::string colors = std::string(""),
        std::string editorsChoice = std::string("false"));
};

