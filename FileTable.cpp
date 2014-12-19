#include "FileTable.h"

FileTable::FileTable(const std::string& filename) {
    init(filename);
}

void FileTable::init(const std::string& filename) {
    csv_file.open(filename);
    int offset = 0 ;
    std::string line;

    while(!csv_file.eof()) {
        getline(csv_file, line);
    }
}

int FileTable::getNumberOfRows() {
	return offsets.size();
}
