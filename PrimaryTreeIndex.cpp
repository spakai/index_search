#include "PrimaryTreeIndex.h"

void PrimaryTreeIndex::buildIndex(Table & table, int column) {
    int rowno = 0;
    for(auto currentRow : table) {
        index.emplace(currentRow[column], rowno++);
    }
}

int PrimaryTreeIndex::size() const {
    return index.size();
}
