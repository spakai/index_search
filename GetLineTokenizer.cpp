#include "GetLineTokenizer.h"

void GetLineTokenizer::tokenize(const string& csvrow) {
    tokens.clear();
    istringstream ss(csvrow);
    while (!ss.eof()) {
        std::string str;
        getline(ss, str,',');
        tokens.push_back(str); 
    }
}
