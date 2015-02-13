#include "Tokenizer.h"

std::string& Tokenizer::operator[](unsigned int i) {
    return tokens.at(i);
}

unsigned int Tokenizer::size() const {
    return tokens.size();
}

Tokenizer& Tokenizer::tokenize(const std::string& csvrow) {
    tokens.clear();
    std::istringstream ss(csvrow);
    while (!ss.eof()) {
        std::string str;
        getline(ss, str,',');
        tokens.push_back(str); 
    }
    return (*this);
}
