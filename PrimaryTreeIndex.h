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
            : hash([] (const std::string & key){return 0;}) {
        }

        PrimaryTreeIndexBase(std::function<int(const std::string & key)> hash)
            :hash(hash) {
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
            for(unsigned int i=0; i<indexes.size(); i++) {
                if(indexes.at(i) !=nullptr) {
                    auto index = indexes.at(i);
                    sizes.push_back(index->size()); 
                } else {
                   sizes.push_back(0); 
                }
            }
            return sizes;
        }

        std::function<int(const std::string & key)> hash;
        std::vector<std::shared_ptr<std::map<std::string,T>>> indexes = {nullptr,nullptr,nullptr};
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

    PrimaryTreeIndex(std::function<int(const std::string & key)> hash)
        :PrimaryTreeIndexBase<int>(hash) {}

    void buildIndex(Table & table, int index_column) {
        int rowno = 0;
        for(auto currentRow : table) {
            std::string key = currentRow[index_column];
            int hashed_index = hash(key);

            if(indexes.at(hashed_index) == nullptr) { 
                indexes[hashed_index] = std::make_shared<std::map<std::string,int>>();     
            }

            auto index = indexes.at(hashed_index);
            index->emplace(currentRow[index_column], rowno++);
        }
    }
};	

template <>
class PrimaryTreeIndex<std::string>: public PrimaryTreeIndexBase<std::string> {
    public:
    PrimaryTreeIndex()
            :PrimaryTreeIndexBase<std::string>() {}

    PrimaryTreeIndex(std::function<int(const std::string & key)> hash)
        :PrimaryTreeIndexBase<std::string>(hash) {}


    void buildIndex(Table & table, int index_column, int value_column) {
            for(auto currentRow : table) {
                std::string key = currentRow[index_column];
                int hashed_index = hash(key);

                if(indexes.at(hashed_index) == nullptr) { 
                    indexes[hashed_index] = std::make_shared<std::map<std::string,std::string>>();     
                }

                auto index = indexes.at(hashed_index);
                index->emplace(currentRow[index_column], currentRow[value_column]);
            }
        }
};
