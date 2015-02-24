#include "gmock/gmock.h" 
#include <string> 

#include "PrimaryTreeIndex.h"
#include "FileTable.h"

using namespace testing;

TEST(PrimaryTreeIndex,GetSizeofIndex) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.size(), Eq(56));      
}

TEST(PrimaryTreeIndex,ExactMatchWhenExactMatchLookupIsCalled) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.exactMatch("01386"), Eq(25));      
}

TEST(PrimaryTreeIndex,ExactMatchWhenBestMatchLookupIsCalled) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.exactMatch("01386"), Eq(25));      
}


TEST(PrimaryTreeIndex,BestMatchLookup) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.bestMatch("019354"), Eq(51)); 
}

TEST(PrimaryTreeIndex,BestMatchLookupEnd) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.bestMatch("019956"), Eq(55));      
}

TEST(PrimaryTreeIndex,NoMatchLookupWhenBestMatchIsCalled) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.bestMatch("0060175559138"), Eq(-1));      
}

TEST(PrimaryTreeIndex,NoMatchLookupWhenExactMatchIsCalled) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.exactMatch("0060175559138"), Eq(-1));      
}
