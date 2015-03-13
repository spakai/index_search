#include "gmock/gmock.h" 
#include "PrimaryTreeIndex.h"
#include "PrimaryHashIndex.h"
#include "FileTable.h"
#include "TestTimer.h"
#include <vector>
#include <random>

using namespace testing;

class IndexBenchMarkTest : public Test {
    public:
        FileTable ft;
        PrimaryTreeIndex treeIndex;
        PrimaryHashIndex hashIndex;
        std::vector<std::string> keysToSearch;

        void SetUp() override {
            ft.init("../csv/large_data.csv");
            treeIndex.buildIndex(ft, 0);
            hashIndex.buildIndex(ft, 0);
            int rows = ft.getNumberOfRows();

            std::default_random_engine dre;
            std::uniform_int_distribution<int> di(0,rows);
            for (int i=0; i<200; ++i) {
                auto tokens = ft.getRow(di(dre));
                keysToSearch.push_back(tokens[0]);
            }
            
        } 
};

TEST_F(IndexBenchMarkTest,PrimaryTreeIndex) {
    TestTimer timer("Primary Tree Index");
    for(auto it=keysToSearch.begin(); it!= keysToSearch.end(); ++it) {
        treeIndex.exactMatch(*it);
    }
}

TEST_F(IndexBenchMarkTest,PrimaryHashIndex) {
    TestTimer timer("Primary Hash Index");
    for(auto it=keysToSearch.begin(); it!= keysToSearch.end(); ++it) {
        hashIndex.exactMatch(*it);
    }
}

