#include "gmock/gmock.h" 
#include "iostream"

#include "FileTable.h"

using namespace testing;

TEST(FileTable,ReadsTillEOF) {
    std::ifstream in;
    in.open("../csv/sample.csv"); 
    
    Table t(in);

    int numberOfRows=0;

    std::for_each(t,Table(), [&numberOfRows](const std::string& record){ ++numberOfRows; });
 
    ASSERT_THAT(numberOfRows,Eq(5));
}
