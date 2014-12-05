#include <string>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <algorithm>

class Table {

private:
    std::ifstream* csv_file;
    std::string currentLine;
    bool bad;
public:

    Table():bad(true) {};

    Table(std::ifstream& in) : bad(false), csv_file(&in) {
        this->operator++();
    }

    Table& operator++() {
        std::getline(*csv_file, currentLine);
        if(csv_file->fail()) { 
            bad = true;
        }
        return *this;
    }

    std::string& operator*() {
        return currentLine;
    }

    std::string operator->() {
        this->operator*();
        return currentLine;
    }

    bool operator==(const Table& other)
    {
        return(bad == other.bad);
    }

    bool operator!=(const Table& other)
    {
        return(bad != other.bad);
    }

};
