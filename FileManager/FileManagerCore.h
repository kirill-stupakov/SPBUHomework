#pragma once

#include <string>
#include <filesystem>
#include <fstream>

class FileManagerCore {
private:
    std::filesystem::path currentPath;

public:
    bool isFileExists(const std::filesystem::path &path) const;

    void changePath(const std::string&);

    void appendPath(const std::string&);

    FileManagerCore();

    FileManagerCore(const std::string&);

    std::string getPath() const;

    std::string getFileContent(const std::string &name) const;

    std::filesystem::directory_iterator getFolderContent() const;

    void createFile(const std::string& name) const;

    void createFolder(const std::string& name) const;

    void remove(const std::string& name) const;

};
