#include "gmock/gmock.h" 
#include "SecondaryTreeIndex.h"
#include "FileTable.h"

using namespace testing;

class SecondaryTreeIndexTest : public Test {
    public:
        FileTable ft;
        SecondaryTreeIndex index;

        void SetUp() override {
            ft.init("../csv/abnumber.csv");
            index.buildIndex(ft, 0);
        } 
};

TEST_F(SecondaryTreeIndexTest,GetSizeofIndex) {
   ASSERT_THAT(index.size(), Eq(5));      
}

TEST_F(SecondaryTreeIndexTest,ExactMatchWhenExactMatchLookupIsCalled) {
    ASSERT_THAT(index.exactMatch("00605"), ElementsAre(0,1));      
}

TEST_F(SecondaryTreeIndexTest,BestMatchLookup) {
    ASSERT_THAT(index.bestMatch("006051"), ElementsAre(0,1));      
}

TEST_F(SecondaryTreeIndexTest,ExactMatchWhenBestMatchLookupIsCalled) {
    ASSERT_THAT(index.bestMatch("00605"), ElementsAre(0,1));      
}


