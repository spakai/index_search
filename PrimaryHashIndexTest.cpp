#include "gmock/gmock.h" 
#include "PrimaryHashIndex.h"
#include "FileTable.h"

using namespace testing;

class PrimaryHashIndexTest : public Test {
    public:
        FileTable ft;
        PrimaryHashIndex index;

    void SetUp() override {
        ft.init("../csv/bnumber2.csv");
        index.buildIndex(ft, 0);
    }
};

TEST_F(PrimaryHashIndexTest,GetSizeofIndex) {
    ASSERT_THAT(index.size(), Eq(56));      
}

TEST_F(PrimaryHashIndexTest,ExactMatchLookup) {
    ASSERT_THAT(index.lookup("01386"), Eq(25));      
}

TEST_F(PrimaryHashIndexTest,NoMatchLookup) {
    ASSERT_THAT(index.lookup("0060175559138"), Eq(-1));      
}
