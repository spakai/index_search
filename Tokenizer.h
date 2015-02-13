#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>

class Tokenizer {
    public:
        Tokenizer() {};
        ~Tokenizer() {};
        Tokenizer& tokenize(const std::string& csvrow);
        std::string& operator[] (unsigned int i);
        unsigned int size() const;

    protected:
        std::vector<std::string> tokens;
};
