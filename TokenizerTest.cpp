#include "gmock/gmock.h" 
#include "Tokenizer.h"

using namespace testing;

class TokenizerTest : public Test {
    public:
        Tokenizer tok;
        std::string s{"A,B,C"};
};

TEST_F(TokenizerTest,GetFirstColumnofARow) {
    tok.tokenize(s,',');
    ASSERT_THAT(tok[0],Eq("A"));
}

TEST_F(TokenizerTest, GetLastColumnofARow) {
    tok.tokenize(s,',');
    ASSERT_THAT(tok[2], Eq("C"));
}

TEST_F(TokenizerTest, GetInvalidColumnofARow) {
    tok.tokenize(s,',');
    ASSERT_THROW(tok[100], std::out_of_range);
}

TEST_F(TokenizerTest, NumberOfTokens) {
    tok.tokenize(s,',');
    ASSERT_THAT(tok.size(), Eq(3));
}
