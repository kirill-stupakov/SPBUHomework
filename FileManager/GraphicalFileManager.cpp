#include "GraphicalFileManager.h"

GraphicalFileManager::GraphicalFileManager() {
    options.emplace_back("Change path", changeFolder);
    options.emplace_back("List content", listContent);
    options.emplace_back("Create folder", createFolder);
    options.emplace_back("Create file", createFile);
    options.emplace_back("Remove", remove);
    options.emplace_back("Show file content", showFileContent);
    options.emplace_back("Exit", exit);
}

GraphicalFileManager::GraphicalFileManager(const std::string &path) : GraphicalFileManager() {
    fileManager.changePath(path);
}

void GraphicalFileManager::changeFolder() {
    std::cout << "Destination: ";
    std::string newPath;
    std::cin >> newPath;
    try {
        fileManager.changePath(newPath);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void GraphicalFileManager::listContent() {
    const auto content = fileManager.getFolderContent();
    for (const auto& file: content) {
        std::cout << "[" << (file.is_directory() ? "DIR" : "FIL") << "] ";
        std::cout << file.path().filename() << "\n";
    }
}

void GraphicalFileManager::createFolder() {
    std::cout << "Folder name: ";
    std::string name;
    std::cin >> name;
    try {
        fileManager.createFolder(name);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void GraphicalFileManager::createFile() {
    std::cout << "File name: ";
    std::string name;
    std::cin >> name;
    try {
        fileManager.createFile(name);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void GraphicalFileManager::remove() {
    std::cout << "Name: ";
    std::string name;
    std::cin >> name;
    try {
        fileManager.remove(name);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void GraphicalFileManager::showFileContent() {
    std::cout << "Name: ";
    std::string name;
    std::cin >> name;
    try {
        std::cout << fileManager.getFileContent(name);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void GraphicalFileManager::exit() {
    shouldExit = true;
}

void GraphicalFileManager::renderCurrentPath() const {
    std::cout << "Current path: " << fileManager.getPath() << "\n";
}

void GraphicalFileManager::renderOptions() const {
    int counter = 1;
    for (const auto &option: options) {
        std::cout << "[" << counter << "] " << option.label << "\n";
        counter++;
    }
}

void GraphicalFileManager::chooseOption() {
    std::cout << "Choose option: ";
    int option;
    std::cin >> option;
    while (option < 1 || option > options.size()) {
        std::cout << "Wrong option. Please, try again: ";
        std::cin >> option;
    }
    selectedOption = option - 1;
}

void GraphicalFileManager::executeOption() {
    options[selectedOption].action();
}

void GraphicalFileManager::drawSeparator() const {
    std::cout << "\n";
    for (int i = 0; i < 70; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

void GraphicalFileManager::start() {
    while (!shouldExit) {
        drawSeparator();
        renderCurrentPath();
        renderOptions();
        chooseOption();
        executeOption();
    }
}







