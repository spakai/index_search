#include <vector>
#include <string>
#include <fstream>

class FileTable {
    public:
        FileTable(std::string& filename);
        init(std::string& filename);

    private:
        ifstream csv_file;
        std::vector<int> offsets;
        std::vector<int> lengths;
};
