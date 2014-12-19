#include "FileTable.h"

FileTable::FileTable(std::string& filename) {
    init(filename);
}

FileTable::init(std::string& filename) {
    csv_file.open(filename);
    int offset = 0 ;
    std::string line;

    while(! csv_file.eof()) {
        getline(csv_file, line);
        offsets.push_back(offset);  
    }
}
