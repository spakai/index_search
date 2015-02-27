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

int PrimaryHashIndex::exactMatch(const std::string& key) const {
    auto it = index.find(key);
    return it == index.end() ? -1 : it->second;
} 


