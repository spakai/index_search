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

TEST(PrimaryTreeIndex,ExactMatchLookup) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.lookup("01386"), Eq(25));      
}

TEST(PrimaryTreeIndex,BestMatchLookup) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.lookup("019354"), Eq(51)); 
}

TEST(PrimaryTreeIndex,BestMatchLookupEnd) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.lookup("019956"), Eq(55));      
}

TEST(PrimaryTreeIndex,NoMatchLookup) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.lookup("0060175559138"), Eq(-1));      
}
