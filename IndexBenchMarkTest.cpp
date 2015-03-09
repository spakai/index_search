#include "gmock/gmock.h" 
#include "PrimaryTreeIndex.h"
#include "FileTable.h"

#include <vector>
#include <random>

using namespace testing;

class IndexBenchMarkTest : public Test {
    public:
        FileTable ft;
        PrimaryTreeIndex index;
        std::vector<int> keysToSearch;

        void SetUp() override {
            ft.init("../csv/bnumber2.csv");
            index.buildIndex(ft, 0);
            int rows = ft.getNumberOfRows();
            std::default_random_engine dre;
            std::uniform_int_distribution<int> di(0,rows);
            for (int i=0; i<20; ++i) {
                std::cout << di(dre) << " ";
            }
            std::cout << std::endl;
            
        } 
};

TEST_F(IndexBenchMarkTest,GetSizeofIndex) {
   ASSERT_THAT(index.size(), Eq(56));      
}

