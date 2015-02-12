#include "FileTable.h"

void FileTable::init(const std::string& filename) {
    csv_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);	
    csv_file.open(filename);

	try {
		int offset {0};
		std::string line {}; 
		while(true) {
			getline(csv_file, line);
			offsets.push_back(offset);
			offset += line.length() + 1;
			lengths.push_back(line.length());
		} 
	} catch (...) {
		if (!csv_file.eof()) {
			throw;
		} else {
			csv_file.clear();			
		}
	}
}

int FileTable::getNumberOfRows() {
	return offsets.size();
}

std::string& FileTable::getRow(int index) {

    if(index < 0 || index > getNumberOfRows() - 1) { 
        throw std::out_of_range("index out of range");
    }

    csv_file.seekg(offsets[index], std::ios_base::beg);
    char * buffer = new char[lengths[index]];
    csv_file.read(buffer, lengths[index]);
    currentLine.assign(buffer,lengths[index]);
    delete[] buffer;
    return currentLine;
}
