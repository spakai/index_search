#pragma once

#include "Index.h"
#include "IndexSearchException.h"
#include <map>
#include <functional>

template <typename T>
class PrimaryTreeIndex: public Index {
	public:
        PrimaryTreeIndex(std::function<void()> hash)
            : hash(hash) 
        {}
        PrimaryTreeIndex()
            : hash([]{return 0;})
        {}
        virtual void buildIndex(Table & table, int index_column);
        virtual void buildIndex(Table & table, int index_column, int value_column);
        virtual const T& exactMatch(const std::string& key) const;
        virtual const T& bestMatch(const std::string& key) const;
        int size() const;

	private:
        std::map<std::string,T> index;
        std::function<int()> hash;
};
