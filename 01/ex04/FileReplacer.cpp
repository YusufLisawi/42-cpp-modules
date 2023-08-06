#include "FileReplacer.hpp"
#include <iostream>
#include <fstream>

FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2) 
: filename(filename), s1(s1), s2(s2)
{
	std::cout << "FileReplacer constructed" << std::endl;
}

FileReplacer::~FileReplacer() {
	std::cout << "FileReplacer destructed" << std::endl;
}
bool FileReplacer::replace() {
    std::ifstream inFile(this->filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << this->filename << std::endl;
        return false;
    }

    std::ofstream outFile(this->filename + ".replace");
    if (!outFile) {
        std::cerr << "Error creating output file: " << this->filename << ".replace" << std::endl;
        inFile.close();
        return false;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::string newLine;
        size_t pos = 0;
        while (pos < line.length()) {
            size_t foundPos = line.find(this->s1, pos);
            if (foundPos == std::string::npos) {
                newLine += line.substr(pos);
                break;
            }
            newLine += line.substr(pos, foundPos - pos);
            newLine += this->s2;
            pos = foundPos + this->s1.length();
        }
        if (inFile.eof() && line.empty() == false)
            outFile << newLine;
        else
            outFile << newLine << std::endl;
    }

    inFile.close();
    outFile.close();

    return true;
}

