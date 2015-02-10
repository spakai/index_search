#include "Index.h"
#include <map>

class PrimaryTreeIndex: public Index {
	public:
 		virtual void buildIndex(Table & table, int column)=0;

	private:
		std::map<std::string,int > index;
};
