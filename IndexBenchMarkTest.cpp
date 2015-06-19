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
        PrimaryTreeIndex<int> treeIndex;
        PrimaryHashIndex hashIndex;
        std::vector<std::string> ExactKeysToSearch;
        std::vector<std::string> BestMatchKeysToSearch;

        void SetUp() override {
            ft.init("../csv/large_data.csv");
            treeIndex.buildIndex(ft, 0);
            hashIndex.buildIndex(ft, 0);
            int rows = ft.getNumberOfRows();

            std::default_random_engine dre;
            std::uniform_int_distribution<int> di(0,rows-1);
            for (int i=0; i<50000; ++i) {
                auto tokens = ft.getRow(di(dre));
                ExactKeysToSearch.push_back(tokens[0]);
                BestMatchKeysToSearch.push_back(tokens[0] + "999");
            }
            
        } 
};

TEST_F(IndexBenchMarkTest,PrimaryTreeIndexExactMatch) {
    TestTimer timer("Primary Tree Index Exact Match", ExactKeysToSearch.size());
    for(auto it=ExactKeysToSearch.begin(); it!= ExactKeysToSearch.end(); ++it) {
        treeIndex.exactMatch(*it);
    }
}

TEST_F(IndexBenchMarkTest,PrimaryHashIndexExactMatch) {
    TestTimer timer("Primary Hash Index Exact Match", ExactKeysToSearch.size());
    for(auto it=ExactKeysToSearch.begin(); it!= ExactKeysToSearch.end(); ++it) {
        hashIndex.exactMatch(*it);
    }
}

TEST_F(IndexBenchMarkTest,PrimaryTreeIndexBestMatch) {
    TestTimer timer("Primary Tree Index Best Match",BestMatchKeysToSearch.size());
    for(auto it=BestMatchKeysToSearch.begin(); it!= BestMatchKeysToSearch.end(); ++it) {
        treeIndex.bestMatch(*it);
    }
}

