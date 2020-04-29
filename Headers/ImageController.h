#pragma once
#include <iostream>
#include <curl/curl.h>
#include<filesystem>

class ImageController
{
private:
    std::string outfilename;
public:
    ImageController() : outfilename{ std::filesystem::current_path().string() + std::string("\\wallpaper.jpg") } {};
    ImageController(std::string outFileName) : outfilename{ std::filesystem::current_path().string() + "\\" + outFileName} {};
    ~ImageController() {};

    std::string DownloadImage(std::string url);
    bool changeWallpaper(std::string wallpaperFileName);
};

