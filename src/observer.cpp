#include "observer.h"
#include <fstream>

FileLogger::FileLogger(const std::string& fname) : filename(fname) {}

void FileLogger::onNotify(const std::string& event) {
    std::ofstream fout(filename, std::ios::app);
    fout << event << std::endl;
}
