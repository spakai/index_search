#pragma once

#include <string>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <algorithm>

class Table {
private:
    bool bad;
    std::ifstream* csv_file;
    std::string currentLine;
public:
    Table();
    Table(std::ifstream& in);
    Table& operator++(); 
    std::string& operator*();
    std::string& operator->(); 
    bool operator==(const Table& other);
    bool operator!=(const Table& other);
};
