#include "PrimaryTreeIndex.h"
#include <iostream>
template <typename T>
PrimaryTreeIndex<T>::PrimaryTreeIndex(std::function<int(const std::string & key)> hash)
            : hash(hash) {}

template <typename T>
PrimaryTreeIndex<T>::PrimaryTreeIndex()
            : hash([] (const std::string & key){return 0;}) {
        for(unsigned int n=0; n<10; n++) {
            indexes.push_back(nullptr);
        }
}

template <> inline
void PrimaryTreeIndex<int>::buildIndex(Table & table, int index_column) {
    int rowno = 0;
    for(auto currentRow : table) {
        std::string key = currentRow[index_column];
        int hashed_index = hash(key);
        if(indexes.at(hashed_index) != nullptr) { 
            auto index = indexes.at(hashed_index);
            index->emplace(currentRow[index_column], rowno++);
        } else {
            indexes[hashed_index] = std::make_shared<std::map<std::string,int>>();     
            auto index = indexes.at(hashed_index);
            index->emplace(currentRow[index_column], rowno++);
        }
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
        std::string key = currentRow[index_column];
        int hashed_index = hash(key);
        if(indexes.at(hashed_index) != nullptr) { 
            auto index = indexes.at(hashed_index);
            index->emplace(currentRow[index_column], currentRow[value_column]);
        } else {
            indexes[hashed_index] = std::make_shared<std::map<std::string,std::string>>();     
            auto index = indexes.at(hashed_index);
            index->emplace(currentRow[index_column], currentRow[value_column]);
        }
    }
}

template <typename T>
int PrimaryTreeIndex<T>::size() const {
    auto index = indexes.at(0);
    return index->size();
}

template <typename T>
const T&  PrimaryTreeIndex<T>::exactMatch(const std::string& key) const {
    int hashed_index = hash(key);
    auto index = indexes.at(hashed_index);
    auto it = index->find(key);
    if(it == index->end()) {
        throw IndexSearchException("No match found"); 
    } else {
        return it->second;
    }
} 

template <typename T>
const T& PrimaryTreeIndex<T>::bestMatch(const std::string& key) const {

    auto index = indexes.at(hash(key));
    auto lower_bound = index->lower_bound(key);
    if(lower_bound != index->end() && lower_bound->first == key) {
        return lower_bound->second; 
    } else {
        typename std::map<std::string,T>::const_reverse_iterator rbegin(lower_bound); 
        typename std::map<std::string,T>::const_reverse_iterator rend(index->begin()); 
        for(auto it = rbegin; it!=rend; it++) {
            auto idx = key.find(it->first);
            if(idx != std::string::npos) {
                return it->second;
            } 
        }
    }

    throw IndexSearchException("No match found");
}
