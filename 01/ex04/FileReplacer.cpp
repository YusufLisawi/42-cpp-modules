/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:18:29 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/08 11:18:30 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>
#include <fstream>

FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2) 
: filename(filename), s1(s1), s2(s2)
{
}

FileReplacer::~FileReplacer()
{
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
        size_t pos = 0;
        while ((pos = line.find(this->s1, pos)) != std::string::npos) {
            line.erase(pos, this->s1.length());
            line.insert(pos, this->s2);
            pos += this->s2.length();
        }
        if (inFile.eof() && !line.empty())
            outFile << line;
        else
            outFile << line << std::endl;
    }

    inFile.close();
    outFile.close();

    return true;
}

