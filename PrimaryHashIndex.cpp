#include "PrimaryHashIndex.h"

void PrimaryHashIndex::buildIndex(Table & table, int column) {
    int rowno = 0;
    for(auto &currentRow : table) {
        index.emplace(currentRow[column], rowno++);
    }
}

int PrimaryHashIndex::size() const {
    return index.size();
}

int PrimaryHashIndex::lookup(const std::string& key) const {
    auto lookup = index.find(key);
    if(lookup != index.end() && lookup->first == key) {
        return lookup->second; 
    }

    return -1;
}
