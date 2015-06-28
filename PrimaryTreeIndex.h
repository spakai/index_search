#include "Index.h"
#include "IndexSearchException.h"
#include <map>

template <typename T>
class PrimaryTreeIndex: public Index {
	public:
        virtual void buildIndex(Table & table, int index_column);
        virtual void buildIndex(Table & table, int index_column, int value_column);
        virtual const T& exactMatch(const std::string& key) const;
        virtual const T& bestMatch(const std::string& key) const;
        int size() const;

	private:
        std::map<std::string,T> index;
};
