#pragma once

#include "Index.h"
#include "IndexSearchException.h"
#include <vector>
#include <memory>
#include <map>
#include <functional>

template <typename T>
class PrimaryTreeIndexBase: public Index {
	public:
        PrimaryTreeIndexBase()
            : hash([] (const std::string & key){return 0;}) 
        {
            indexes.push_back(std::make_shared<std::map<std::string,T>>());     
        }

        PrimaryTreeIndexBase(std::function<int(const std::string & key)> hash, unsigned int mapSize)
            :hash(hash)
        {
            for(unsigned int i=0; i < mapSize ; i++) {
                 indexes.push_back(std::make_shared<std::map<std::string,T>>());     
            }
        } 
        void buildIndex(Table & table, int index_column) {}
 
        void buildIndex(Table & table, int index_column, int value_column) {}

        const T& exactMatch(const std::string& key) const {
            auto index = indexes.at(hash(key));
            auto it = index->find(key);
            if(it == index->end()) {
                throw IndexSearchException("No match found"); 
            } else {
                return it->second;
            }
        } 

        const T& bestMatch(const std::string& key) const {
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

        std::vector<int> size() const {
            std::vector<int> sizes;
            for(auto index : indexes) {
                if(index == nullptr) { 
                    sizes.push_back(0);
                } else { 
                    sizes.push_back(index->size()); 
                }
            }

            return sizes;
        }

        std::vector<std::shared_ptr<std::map<std::string,T>>> indexes;
        std::function<int(const std::string & key)> hash;
};

template<typename T>
class PrimaryTreeIndex : public PrimaryTreeIndexBase<T> {
    public:
        PrimaryTreeIndex()                                                                                        
            :PrimaryTreeIndexBase<T>() {}                                                                   
                                                                                                              
        PrimaryTreeIndex(std::function<int(const std::string & key)> hash)                                        
            :PrimaryTreeIndexBase<T>(hash) {}             
};


template <>
class PrimaryTreeIndex<int>: public PrimaryTreeIndexBase<int> {
    public:
    PrimaryTreeIndex()
            :PrimaryTreeIndexBase<int>() {}

    PrimaryTreeIndex(std::function<int(const std::string & key)> hash, unsigned int mapSize)
        :PrimaryTreeIndexBase<int>(hash, mapSize) {}

    void buildIndex(Table & table, int index_column) {
        int rowno = 0;
        for(auto currentRow : table) {
            std::string key = currentRow[index_column];
            auto index = indexes.at(hash(key));
            index->emplace(currentRow[index_column], rowno++);
        }
    }
};	

template <>
class PrimaryTreeIndex<std::string>: public PrimaryTreeIndexBase<std::string> {
    public:
    PrimaryTreeIndex()
            :PrimaryTreeIndexBase<std::string>() {}

    PrimaryTreeIndex(std::function<int(const std::string & key)> hash, unsigned int mapSize)
        :PrimaryTreeIndexBase<std::string>(hash, mapSize) {}

    void buildIndex(Table & table, int index_column, int value_column) {
            for(auto currentRow : table) {
                std::string key = currentRow[index_column];
                auto index = indexes.at(hash(key));
                index->emplace(currentRow[index_column], currentRow[value_column]);
            }
        }
};
