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

std::vector<int> SecondaryTreeIndex::exactMatch(const std::string& key) const {
    std::vector<int> tmp{-1};
    return tmp;
}
