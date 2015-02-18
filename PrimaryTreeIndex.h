#include "Index.h"
#include <map>

class PrimaryTreeIndex: public Index {
	public:
        virtual void buildIndex(Table & table, int column);
        virtual int lookup(const std::string& key) const;
        int size() const;

	private:
        std::map<std::string,int> index;
};
