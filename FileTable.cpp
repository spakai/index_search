#include "FileTable.h"

FileTable::FileTable(const std::string& filename) {
    init(filename);
}

void FileTable::init(const std::string& filename) {
    csv_file.open(filename);
    int offset = 0 ;
    std::string line;

    csv_file.seekg(0, std::ios::beg);
    while(!csv_file.eof()) {
        getline(csv_file, line);
        if(!csv_file.fail()){
            offsets.push_back(offset);
            offset += line.length()+1;
            lengths.push_back(line.length());
        }
    }

    csv_file.clear();
}

int FileTable::getNumberOfRows() {
	return offsets.size();
}

std::string FileTable::getRow(int index) {

    if(index < 0 || index > getNumberOfRows() - 1) { 
        throw std::out_of_range("index out of range");
    }


    csv_file.seekg(offsets[index], std::ios_base::beg);
    char * buffer = new char[lengths[index]];
    csv_file.read(buffer, lengths[index]);
    std::string t(buffer);	
    delete[] buffer;
    return t;
}
