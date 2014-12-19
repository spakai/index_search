#include <vector>
#include <string>
#include <fstream>

class FileTable {
    public:
		FileTable() {};
		~FileTable() {};
        FileTable(const std::string& filename);
        void init(const std::string& filename);
		int getNumberOfRows();

    private:
        std::ifstream csv_file;
        std::vector<int> offsets;
        std::vector<int> lengths;
};
