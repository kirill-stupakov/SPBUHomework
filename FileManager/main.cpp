#include <iostream>
#include "FileManagerCore.h"
using namespace std;

int main() {
    FileManagerCore manager;
    cout << manager.getPath() << "\n";

    manager.changePath("C:\\\\Users\\Public");
    cout << manager.getPath() << "\n";

    manager.createFolder("My New Folder");
    manager.appendPath("My New Folder");
    manager.createFile("qwe.txt");

    return 0;
}
