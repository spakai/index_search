#include "gmock/gmock.h" 
#include "iostream"

#include "Table.h"

using namespace testing;

TEST(TableIterator,ReadsTillEOF) {
    std::ifstream in;
    in.open("../csv/sample.csv"); 
    
    Table t(in);

    int numberOfRows=0;

    std::for_each(t,Table(), [&numberOfRows](const std::string& record){ ++numberOfRows; });
 
    ASSERT_THAT(numberOfRows,Eq(5));
}

TEST(TableIterator,ReadLastRow) {

    std::ifstream in;
    in.open("../csv/sample.csv"); 
    
    Table t(in);

    std::string line; 

    std::for_each(t,Table(), [&line](const std::string& record){ line = record; });
 
    ASSERT_THAT(line,Eq("12,DF,ER,AD,JK"));

}
