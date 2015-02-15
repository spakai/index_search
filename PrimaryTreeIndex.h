#include "Index.h"
#include <map>

class PrimaryTreeIndex: public Index {
	public:
 		virtual void buildIndex(Table & table, int column);
        int size() const;

	private:
        std::map<std::string,int> index;
};
