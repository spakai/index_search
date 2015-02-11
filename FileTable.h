#include "Table.h"

class FileTable : public Table{
    public:
        FileTable() {};
        ~FileTable() {};
        FileTable(const std::string& filename);
        void init(const std::string& filename);
        virtual int getNumberOfRows();
        virtual std::string& getRow(int index);
};
