#include "MainWindow.h"

MainWindow::MainWindow() {
    this->apiController = new APIController();
    this->parser = new JSONParser(JSONFILENAME);
    this->imageController = ImageController(WALLPAPERFILENAME);
    this->editorsChoice = "false";
    this->colors = "";
}

void MainWindow::readUserArgs() {
    std::cout << "What do you want to see on your new wallpaper?" << std::endl;
    std::cin >> this->searchTerm;

    std::cout << "Do you want your wallpaper to be \"Editor's Choice\" (y/n)?" << std::endl;
    std::string answer;
    std::cin >> answer;
    if (answer == "y") {
        this->editorsChoice = "true";
    }

    std::cout << "Do you want your wallpaper in specific colors (y/n)?" << std::endl;
    std::cin >> answer;
    if (answer == "y") {
        std::cout << "What color do you prefer?" << std::endl;
        std::cout << "GREYSCALE: 0" << std::endl;
        std::cout << "ORANGE: 1" << std::endl;
        std::cout << "GREEN: 2" << std::endl;
        std::cout << "TURQUOISE: 3" << std::endl;
        std::cout << "WHITE: 4" << std::endl;
        std::cout << "BLACK: 5" << std::endl;
        int color;
        std::cin >> color;
        switch (color) {
            case 0:
                this->colors = "greyscale";
                break;
            case 1:
                this->colors = "orange";
                break;
            case 2:
                this->colors = "green";
                break;
            case 3:
                this->colors = "turquoise";
                break;
            case 4:
                this->colors = "white";
                break;
            case 5:
                this->colors = "black";
                break;
            default:
                this->colors = "";
        }
    }

    system("CLS");
    return;
}

bool MainWindow::saveAPIResults() {
    try {
        apiController->getPhotos(JSONFILENAME, this->getSearchTerm(), this->getColors(), this->getEditorsChoice()).wait();
        if (parser->emptyJSON()) {
            std::cout << "Sadly, there are no results for your query";
            return false;
        }
        return true;
    }
    catch (const std::exception& e) {
        std::cout << "Error exception: " << e.what() << std::endl;
        return false;
    }
}

void MainWindow::changeWallpaper() {
    std::string anwser;
    std::string url;
    std::string backgroundFileName;
    do {
        std::cout << "Just a second... " << std::endl;
        url = parser->getRandomImageUrl();
        backgroundFileName = imageController.DownloadImage(url);
        if (!imageController.changeWallpaper(backgroundFileName)) { //wallpaper doesnt change
            return;
        }
        std::cout << "Do you want to test your luck again (y/n)?" << std::endl;
        std::cin >> anwser;
        system("CLS");
    } while (anwser == "y");
    remove(JSONFILENAME.c_str());
}

std::string MainWindow::getSearchTerm() {
    return this->searchTerm;
}

std::string MainWindow::getEditorsChoice() {
    return this->editorsChoice;
}

std::string MainWindow::getColors() {
    return this->colors;
}
