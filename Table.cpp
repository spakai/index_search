#include "Table.h"

Table::Table():bad(true) {
    
}

Table::Table(std::ifstream& in) : bad(false), csv_file(&in) {
    this->operator++();
}

Table& Table::operator++() {
    std::getline(*csv_file, currentLine);
    if(csv_file->fail()) { 
        bad = true;
    }
    return *this;
}

std::string& Table::operator*() {
    return currentLine;
}

std::string& Table::operator->() {
    this->operator*();
    return currentLine;
}

bool Table::operator==(const Table& other)
{
    return(bad == other.bad);
}

bool Table::operator!=(const Table& other)
{
    return(bad != other.bad);
}
