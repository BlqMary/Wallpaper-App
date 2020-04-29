#pragma once
#include <string>
#include <iostream>
#include "APIController.h"
#include "JSONParser.h"
#include "ImageController.h"

const std::string JSONFILENAME = "results.json";
const std::string WALLPAPERFILENAME = "wallpaper.jpg";

class MainWindow
{
    APIController * apiController;
    JSONParser * parser;
    ImageController imageController;
    std::string searchTerm;
    std::string editorsChoice;
    std::string colors;

public:
    MainWindow();
    ~MainWindow() {};

    void readUserArgs();
    bool saveAPIResults();
    void changeWallpaper();

    std::string getSearchTerm();
    std::string getEditorsChoice();
    std::string getColors();
};


