#include "PrimaryTreeIndex.h"

template <> inline
void PrimaryTreeIndex<int>::buildIndex(Table & table, int index_column) {
    int rowno = 0;
    for(auto currentRow : table) {
        index.emplace(currentRow[index_column], rowno++);
    }
}

template <> inline
void PrimaryTreeIndex<int>::buildIndex(Table & table, int index_column, int value_column) {
}

template <> inline
void PrimaryTreeIndex<std::string>::buildIndex(Table & table, int index_column) {
}

template <> inline
void PrimaryTreeIndex<std::string>::buildIndex(Table & table, int index_column, int value_column) {
    for(auto currentRow : table) {
        index.emplace(currentRow[index_column], currentRow[value_column]);
    }
}

template <typename T>
int PrimaryTreeIndex<T>::size() const {
    return index.size();
}

template <typename T>
const T&  PrimaryTreeIndex<T>::exactMatch(const std::string& key) const {
    auto it = index.find(key);
    if(it == index.end()) {
        throw IndexSearchException("No match found"); 
    } else {
        return it->second;
    }
} 

template <typename T>
const T& PrimaryTreeIndex<T>::bestMatch(const std::string& key) const {
    auto lower_bound = index.lower_bound(key);
    if(lower_bound != index.end() && lower_bound->first == key) {
        return lower_bound->second; 
    } else {
        typename std::map<std::string,T>::const_reverse_iterator rbegin(lower_bound); 
        typename std::map<std::string,T>::const_reverse_iterator rend(index.begin()); 
        for(auto it = rbegin; it!=rend; it++) {
            auto idx = key.find(it->first);
            if(idx != std::string::npos) {
                return it->second;
            } 
        }
    }

    throw IndexSearchException("No match found");
}
