#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

class Table {
    public:
		virtual int getNumberOfRows()=0;
		virtual std::string& getRow(int index)=0;

    class Iterator {
        public:
            Iterator(Table &table) : table(&table), index(0), eof(false) {}
            Iterator() : eof(true) {}
            Iterator& operator++() {
                ++index;   
                if(index == table->getNumberOfRows()) {
                    eof = true;    
                }
                return (*this);
            }
            Iterator operator++(int);
            std::string operator*() {
                return table->getRow(index);
            }
            std::string& operator->();
            bool operator==(const Iterator& other) {
                return (eof == other.eof);
            }
            bool operator!=(const Iterator& other) {
                return (eof != other.eof);
            }


        protected:
            Table *table;
            int index;
            bool eof;
    };

        Iterator begin() {
            return Iterator(*this);
        }

        Iterator end() {
            return Iterator();
        }

    protected:
        std::ifstream csv_file;
        std::vector<int> offsets;
        std::vector<int> lengths;
        std::string currentLine;
};
