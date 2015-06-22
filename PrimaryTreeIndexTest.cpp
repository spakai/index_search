#include "gmock/gmock.h" 
#include "PrimaryTreeIndex.cpp"
#include "FileTable.h"

using namespace testing;

class PrimaryTreeIndexTest : public Test {
    public:
        FileTable ft;
        PrimaryTreeIndex<int> index;

        void SetUp() override {
            ft.init("../csv/bnumber2.csv");
            index.buildIndex(ft, 0);
        } 
};

TEST_F(PrimaryTreeIndexTest,GetSizeofIndex) {
   ASSERT_THAT(index.size(), Eq(56));      
}

TEST_F(PrimaryTreeIndexTest,ExactMatchWhenExactMatchLookupIsCalled) {
    ASSERT_THAT(index.exactMatch("01386"), Eq(25));      
}

TEST_F(PrimaryTreeIndexTest,ExactMatchWhenBestMatchLookupIsCalled) {
    ASSERT_THAT(index.bestMatch("01386"), Eq(25));      
}

TEST_F(PrimaryTreeIndexTest,BestMatchLookup) {
    ASSERT_THAT(index.bestMatch("019354"), Eq(51)); 
}

TEST_F(PrimaryTreeIndexTest,BestMatchLookupEnd) {
    ASSERT_THAT(index.bestMatch("019956"), Eq(55));      
}

TEST_F(PrimaryTreeIndexTest,NoMatchLookupWhenBestMatchIsCalled) {
    ASSERT_THROW(index.bestMatch("0060175559138"), IndexSearchException);      
}

TEST_F(PrimaryTreeIndexTest,NoMatchLookupWhenExactMatchIsCalled) {
    ASSERT_THROW(index.exactMatch("0060175559138"), IndexSearchException);      
}
