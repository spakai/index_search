#pragma once

#include "Tokenizer.h"
#include <regex>

using namespace std;

class RegexTokenizer : public Tokenizer {

    public:
        RegexTokenizer() {};
        ~RegexTokenizer() {};
        virtual void tokenize(const std::string& csvrow);
};
