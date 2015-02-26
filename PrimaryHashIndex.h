#include "Index.h"
#include <unordered_map>

class PrimaryHashIndex: public Index {
	public:
        virtual void buildIndex(Table & table, int column);
        virtual int exactMatch(const std::string& key) const;
        int size() const;

	private:
        std::unordered_map<std::string,int> index;
};
