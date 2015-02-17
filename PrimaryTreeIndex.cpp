#include "PrimaryTreeIndex.h"

void PrimaryTreeIndex::buildIndex(Table & table, int column) {
    int rowno = 0;
    for(auto &currentRow : table) {
        index.emplace(currentRow[column], rowno++);
    }
}

int PrimaryTreeIndex::size() const {
    return index.size();
}

int PrimaryTreeIndex::lookup(const std::string& key) {
    auto bounds = index.equal_range(key);
    auto lower_bound = bounds.first;
    if(lower_bound->first == key) {
        return lower_bound->second; 
    }
}
