#include "Index.h"
#include <map>
#include <set>

class SecondaryTreeIndex: public Index {
	public:
        virtual void buildIndex(Table & table, int column);
        virtual std::set<int> exactMatch(const std::string& key) const;
        int size() const;

	private:
        std::multimap<std::string,int> index;
};
