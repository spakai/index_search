#include "SecondaryTreeIndex.h"

void SecondaryTreeIndex::buildIndex(Table & table, int column) {
    int rowno = 0;
    for(auto &currentRow : table) {
        index.emplace(currentRow[column], rowno++);
    }
}

int SecondaryTreeIndex::size() const {
    return index.size();
}

int SecondaryTreeIndex::lookup(const std::string& key) const {
    return -1;
}
