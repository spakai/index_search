#include "gmock/gmock.h" 
#include <string> 

#include "PrimaryHashIndex.h"
#include "FileTable.h"

using namespace testing;

TEST(PrimaryHashIndex,GetSizeofIndex) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryHashIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.size(), Eq(56));      
}

TEST(PrimaryHashIndex,ExactMatchLookup) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryHashIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.lookup("01386"), Eq(25));      
}

TEST(PrimaryHashIndex,NoMatchLookup) {
    FileTable ft;
    ft.init("../csv/bnumber2.csv");
    PrimaryHashIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.lookup("0060175559138"), Eq(-1));      
}
