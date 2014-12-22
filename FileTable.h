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
};
