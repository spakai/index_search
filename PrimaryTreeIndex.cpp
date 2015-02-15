#include "PrimaryTreeIndex.h"

void PrimaryTreeIndex::buildIndex(Table & table, int column) {
    int offset_index=0;
	for(auto it=table.begin(); it!=table.end(); ++it) {
        // key is row column and value is offset's index or basically row no
        index[(*it)[column]] = offset_index++; 
	}
}

int PrimaryTreeIndex::size() const {
    return index.size();
}
