#pragma once

#include "FileManagerCore.h"
#include "FileManagerOption.h"
#include <iostream>
#include <vector>

class GraphicalFileManager {
private:
    inline static FileManagerCore fileManager;
    int selectedOption = 1;
    inline static bool shouldExit = false;

    static void changeFolder();
    static void listContent();
    static void createFolder();
    static void createFile();
    static void remove();
    static void showFileContent();
    static void exit();

    std::vector<FileManagerOption> options;

    void renderCurrentPath() const;

    void renderOptions() const;

    void chooseOption();

    void executeOption();

    void drawSeparator() const;

public:
    GraphicalFileManager();

    explicit GraphicalFileManager(const std::string&);

    void start();

};
