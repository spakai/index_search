#include "Index.h"
#include <map>

class PrimaryTreeIndex: public Index {
	public:
        virtual void buildIndex(Table & table, int column);
        virtual int exactMatch(const std::string& key) const;
        virtual int bestMatch(const std::string& key) const;
        int size() const;

	private:
        std::map<std::string,int> index;
};
