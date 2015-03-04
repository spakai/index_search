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

std::set<int> SecondaryTreeIndex::exactMatch(const std::string& key) const {
    std::set<int> values;
    auto bounds = index.equal_range(key);

    if(bounds.first != index.end()) {
        for(auto it = bounds.first; it != bounds.second; ++it) {
            values.insert(it->second);
        }         
    } 
    
    return values;
}

std::set<int> SecondaryTreeIndex::bestMatch(const std::string& key) const {
    std::set<int> values;
    auto bounds = index.equal_range(key);

    if(bounds.first != index.end() && bounds.first->first == key) {
        for(auto it = bounds.first; it != bounds.second; ++it) {
            values.insert(it->second);
        }         
    } else {
        std::multimap<std::string,int>::const_reverse_iterator rbegin(bounds.first); 
        std::multimap<std::string,int>::const_reverse_iterator rend(index.begin()); 
        for(auto it = rbegin; it!=rend; it++) {
            auto idx = key.find(it->first);
            if(idx != std::string::npos) {
                values.insert(it->second);
            } 
        }
 

    } 
    
    return values;
}
