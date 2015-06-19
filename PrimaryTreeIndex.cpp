#include "PrimaryTreeIndex.h"

template <typename T>
void PrimaryTreeIndex<T>::buildIndex(Table & table, int column) {
    int rowno = 0;
    for(auto currentRow : table) {
        index.emplace(currentRow[column], rowno++);
    }
}

template <typename T>
int PrimaryTreeIndex<T>::size() const {
    return index.size();
}

template <typename T>
T PrimaryTreeIndex<T>::exactMatch(const std::string& key) const {
    auto it = index.find(key);
    return it == index.end() ? -1 : it->second;
} 

template <typename T>
T PrimaryTreeIndex<T>::bestMatch(const std::string& key) const {
    auto lower_bound = index.lower_bound(key);
    if(lower_bound != index.end() && lower_bound->first == key) {
        return lower_bound->second; 
    } else {
        std::map<std::string,int>::const_reverse_iterator rbegin(lower_bound); 
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
