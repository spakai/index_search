#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

class FileTable {
    public:
		FileTable() {};
		~FileTable() {};
        FileTable(const std::string& filename);
        void init(const std::string& filename);
		int getNumberOfRows();
		std::string& getRow(int index);

    class Iterator {
        public:
            Iterator(FileTable &table) : table(&table), index(0), eof(false) {}
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


        private:
            FileTable *table;
            int index;
            bool eof;
    };

    private:
        std::ifstream csv_file;
        std::vector<int> offsets;
        std::vector<int> lengths;
		std::string currentLine;
};
