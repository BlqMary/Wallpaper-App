#include "APIController.h"

APIController::APIController() {
    this->fileStream = std::make_shared<ostream>();
}

pplx::task<void> APIController::getPhotos(std::string resultFile, std::string searchTerm, std::string colors,
    std::string editorsChoice) {
    return fstream::open_ostream(to_string_t(resultFile)).then([=](ostream outFile) {
        *this->fileStream = outFile;

        http_client client(U("https://pixabay.com/api/"));
        uri_builder builder(U(""));
        builder.append_query(U("key"), this->key);
        builder.append_query(U("q"), to_string_t(searchTerm));
        builder.append_query(U("orientation"), U("horizontal"));
        builder.append_query(U("category"), U("backgrounds"));
        builder.append_query(U("image_type"), U("photo"));
        builder.append_query(U("per_page"), U("200"));
        builder.append_query(U("editors_choice"), to_string_t(editorsChoice));
        if (colors != "") {
            builder.append_query(U("colors"), to_string_t(colors));
        }
        return client.request(methods::GET, builder.to_string());}).then([=](http_response response) {
            return response.body().read_to_end(fileStream->streambuf());
            }).then([=](size_t) { return fileStream->close(); });
}