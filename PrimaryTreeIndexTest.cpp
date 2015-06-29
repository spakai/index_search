#include "gmock/gmock.h" 
#include "PrimaryTreeIndex.cpp"
#include "FileTable.h"

using namespace testing;

class PrimaryTreeIndexTestWithRowId : public Test {
    public:
        FileTable ft;
        PrimaryTreeIndex<int> index;

        void SetUp() override {
            ft.init("../csv/bnumber2.csv");
            index.buildIndex(ft, 0);
        } 
};

class PrimaryTreeIndexTestWithColumn : public Test {
    public:
        FileTable ft;
        PrimaryTreeIndex<std::string> index;

        void SetUp() override {
            ft.init("../csv/bnumber2.csv");
            index.buildIndex(ft,0,1);
        } 
};

TEST_F(PrimaryTreeIndexTestWithRowId,GetSizeofIndex) {
   ASSERT_THAT(index.size(), Eq(56));      
}

TEST_F(PrimaryTreeIndexTestWithRowId,ExactMatchWhenExactMatchLookupIsCalled) {
    ASSERT_THAT(index.exactMatch("01386"), Eq(25));      
}

TEST_F(PrimaryTreeIndexTestWithRowId,ExactMatchWhenBestMatchLookupIsCalled) {
    ASSERT_THAT(index.bestMatch("01386"), Eq(25));      
}

TEST_F(PrimaryTreeIndexTestWithRowId,BestMatchLookup) {
    ASSERT_THAT(index.bestMatch("019354"), Eq(51)); 
}

TEST_F(PrimaryTreeIndexTestWithRowId,BestMatchLookupEnd) {
    ASSERT_THAT(index.bestMatch("019956"), Eq(55));      
}

TEST_F(PrimaryTreeIndexTestWithRowId,NoMatchLookupWhenBestMatchIsCalled) {
    ASSERT_THROW(index.bestMatch("0060175559138"), IndexSearchException);      
}

TEST_F(PrimaryTreeIndexTestWithRowId,NoMatchLookupWhenExactMatchIsCalled) {
    ASSERT_THROW(index.exactMatch("0060175559138"), IndexSearchException);      
}

TEST_F(PrimaryTreeIndexTestWithColumn,ExactMatchWhenExactMatchLookupIsCalled) {
    ASSERT_THAT(index.exactMatch("01386"), StrEq("Evesham"));
}
