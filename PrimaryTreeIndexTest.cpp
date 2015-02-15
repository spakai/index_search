#include "gmock/gmock.h" 
#include <string> 

#include "PrimaryTreeIndex.h"
#include "FileTable.h"

using namespace testing;

TEST(PrimaryIndex,GetSizeofIndex) {
    FileTable ft;
    ft.init("../csv/bnumber.csv");
    PrimaryTreeIndex index;
    index.buildIndex(ft, 0);
    ASSERT_THAT(index.size(), Eq(5));      
}
