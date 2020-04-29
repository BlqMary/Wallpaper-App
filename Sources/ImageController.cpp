#include "ImageController.h"

std::string ImageController::DownloadImage(std::string url)
{
    CURL* image = curl_easy_init(); //Initialise curl
    if (image)
    {
        FILE* file = fopen(this->outfilename.c_str(), "wb");
        curl_easy_setopt(image, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(image, CURLOPT_WRITEDATA, file);
        curl_easy_setopt(image, CURLOPT_URL, url.c_str());
        CURLcode imgresult = curl_easy_perform(image);
        if (imgresult) {
            std::cout << "Cannot download image" << std::endl;
        }
        fclose(file);
    }
    curl_easy_cleanup(image);
    return this->outfilename;
}

bool ImageController::changeWallpaper(std::string wallpaperFileName) {
    bool succes = SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void*)wallpaperFileName.c_str(), SPIF_SENDWININICHANGE | SPIF_UPDATEINIFILE);
    if (succes){
        std::cout << "Succesfully changed wallpaper!" << std::endl;
        return true;
    }
    else{
        std::cout << "Cannot change wallpaper" << std::endl;
        return false;
    }
}
