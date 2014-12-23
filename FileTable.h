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
		std::string getRow(int index);

    private:
        std::ifstream csv_file;
        std::vector<int> offsets;
        std::vector<int> lengths;

    class Iterator {
        public:
            Iterator();
            Iterator& operator++();
            Iterator operator++(int);
            std::string& operator*();
            std::string& operator->();
            bool operator==(const Iterator& other);
            bool operator!=(const Iterator& other);

        private:
            int index;
    };
};
