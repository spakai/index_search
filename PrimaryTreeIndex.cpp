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

int PrimaryTreeIndex::exactMatch(const std::string& key) const {
    auto it = index.find(key);
    return it == index.end() ? -1 : it->second;
} 

int PrimaryTreeIndex::bestMatch(const std::string& key) const {
    auto bounds = index.equal_range(key);
    auto lower_bound = bounds.first;
    auto upper_bound = bounds.second;

    if(lower_bound != index.end() && lower_bound->first == key) {
        return lower_bound->second; 
    } else {
        std::map<std::string,int>::const_reverse_iterator rbegin(upper_bound); 
        std::map<std::string,int>::const_reverse_iterator rend(index.begin()); 
        for(auto it = rbegin; it!=rend; it++) {
            auto idx = key.find(it->first);
            if(idx != std::string::npos) {
                return it->second;
            } 
        }
    }

    return -1;
}
