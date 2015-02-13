#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Tokenizer {
    public:
        Tokenizer() {};
        virtual ~Tokenizer() {};
        virtual void tokenize(const std::string& csvrow) = 0;
        std::string& operator[] (unsigned int i);
        unsigned int size() const;

    protected:
        std::vector<std::string> tokens;
};
