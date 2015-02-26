#include "Index.h"
#include <map>

class SecondaryTreeIndex: public Index {
	public:
        virtual void buildIndex(Table & table, int column);
        virtual std::vector<int> exactMatch(const std::string& key) const;
        int size() const;

	private:
        std::multimap<std::string,int> index;
};
