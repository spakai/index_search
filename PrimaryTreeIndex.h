#pragma once

#include "Index.h"
#include "IndexSearchException.h"
#include <vector>
#include <memory>
#include <map>
#include <functional>

template <typename T>
class PrimaryTreeIndex: public Index {
	public:
        PrimaryTreeIndex(std::function<int(const std::string & key)> hash);
        PrimaryTreeIndex();
        virtual void buildIndex(Table & table, int index_column);
        virtual void buildIndex(Table & table, int index_column, int value_column);
        virtual const T& exactMatch(const std::string& key) const;
        virtual const T& bestMatch(const std::string& key) const;
        int size() const;

	private:
        std::function<int(const std::string & key)> hash;
        std::vector<std::shared_ptr<std::map<std::string,T>>> indexes;
};
