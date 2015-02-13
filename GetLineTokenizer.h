#pragma once

#include "Tokenizer.h"

#include <sstream>

using namespace std;

class GetLineTokenizer : public Tokenizer {
    public:
        GetLineTokenizer() {};
        ~GetLineTokenizer() {};
        virtual void tokenize(const std::string& csvrow);
};
