#include "FileTable.h"

FileTable::FileTable(const std::string& filename) {
    init(filename);
}

void FileTable::init(const std::string& filename) {
    csv_file.open(filename);
    int offset = 0 ;
    std::string line;

	csv_file.clear();
    csv_file.seekg(0, std::ios::beg);
    while(!csv_file.eof()) {
        getline(csv_file, line);
		if(!csv_file.fail()){
			offsets.push_back(offset);
			offset = line.length()+ 1;
		}
    }
}

int FileTable::getNumberOfRows() {
	return offsets.size();
}

std::string getRow(int index) {
		

}
