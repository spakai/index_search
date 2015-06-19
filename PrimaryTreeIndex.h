#include "Index.h"
#include <map>

template <typename T>
class PrimaryTreeIndex: public Index {
	public:
        virtual void buildIndex(Table & table, int column);
        virtual T exactMatch(const std::string& key) const;
        virtual T bestMatch(const std::string& key) const;
        int size() const;

	private:
        std::map<std::string,T> index;
};
