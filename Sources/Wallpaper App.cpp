#define CURL_STATICLIB

#include "MainWindow.h"
#include <string>
#include <windows.h>
#include <shellapi.h>

int main(){
    MainWindow sm = MainWindow();
    sm.readUserArgs();
    if (sm.saveAPIResults()) {
        sm.changeWallpaper();
    }
    
    return 0;
}

