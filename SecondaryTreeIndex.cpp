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
    std::vector<int> values;
    auto bounds = index.equal_range(key);
    auto lower_bound = bounds.first;
    auto upper_bound = bounds.second; 

    if(lower_bound != index.end()) {
        for(auto it = lower_bound; it != upper_bound; ++it) {
            values.push_back(it->second);
        }         
    } 
    
    return values;
}
