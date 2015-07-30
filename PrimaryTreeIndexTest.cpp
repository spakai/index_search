#include "gmock/gmock.h" 
#include "PrimaryTreeIndex.h"
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

TEST(PrimaryTreeIndexTestWithMultiMaps,GetSizeofIndex) {
   FileTable ft;
   ft.init("../csv/bnumber2.csv");
   std::function<int(const std::string & key)> hash = [] (const std::string & key){return std::stoi(key.substr(0,2));};        
 
   PrimaryTreeIndex<int> index(hash,3);
   index.buildIndex(ft, 0);

   ASSERT_THAT(index.size(), ElementsAre(0,56,0));      
}

TEST_F(PrimaryTreeIndexTestWithRowId,GetSizeofIndex) {
   //ASSERT_THAT(index.size(), Eq(56));      
   ASSERT_THAT(index.size(), ElementsAre(56));      

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

TEST_F(PrimaryTreeIndexTestWithColumn,BestMatchLookup) {
    ASSERT_THAT(index.bestMatch("019354"), StrEq("Yeovil")); 
}

TEST_F(PrimaryTreeIndexTestWithColumn,NoMatchLookupWhenBestMatchIsCalled) {
    ASSERT_THROW(index.bestMatch("0060175559138"), IndexSearchException);      
}
