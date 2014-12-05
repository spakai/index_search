#include <iostream>
#include "Table.h"

int main() {
    std::ifstream in;
    in.open("sample.csv"); 
    Table t(in);

    std::for_each(t,Table(), [](const std::string& record){ std::cout << record << std::endl; });
    return 0;
}
