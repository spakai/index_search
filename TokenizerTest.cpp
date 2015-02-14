#include "gmock/gmock.h" 
#include "Tokenizer.h"

using namespace testing;

TEST(AToken,GetFirstColumnofARow) {
    std::string s{"A,B,C"};
    Tokenizer tok;
    tok.tokenize(s,',');
    ASSERT_THAT(tok[0],Eq("A"));
}

TEST(AToken, GetLastColumnofARow) {
    std::string s{"A,B,C"};
    Tokenizer tok;
    tok.tokenize(s,',');
    ASSERT_THAT(tok[2], Eq("C"));
}

TEST(AToken, GetInvalidColumnofARow) {
    std::string s{"A,B,C"};
    Tokenizer tok;
    tok.tokenize(s,',');
    ASSERT_THROW(tok[100], std::out_of_range);
}

TEST(AToken, NumberOfTokens) {
    std::string s{"A,B,C"};
    Tokenizer tok;
    tok.tokenize(s,',');
    ASSERT_THAT(tok.size(), Eq(3));
}
