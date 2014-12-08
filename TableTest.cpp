#include "gmock/gmock.h" 
#include "iostream"

#include "Table.h"

using namespace testing;

TEST(AToken,ReadsTillEOF) {
    std::ifstream in;
    in.open("sample.csv"); 
    
    Table t(in);

    int numberOfRows=0;

    std::for_each(t,Table(), [&numberOfRows](const std::string& record){ ++numberOfRows; });
 
    ASSERT_THAT(numberOfRows,Eq(5));
}
