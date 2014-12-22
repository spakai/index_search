#include "gmock/gmock.h" 
#include <string> 

#include "FileTable.h"

using namespace testing;

TEST(FileTable,OffsetsAndLengths) {

	FileTable ft("../csv/sample.csv");
 
    ASSERT_THAT(ft.getNumberOfRows(),Eq(5));
}

TEST(FileTable, GetSpecificRow) {
	
	FileTable ft("../csv/sample.csv");

	ASSERT_THAT(ft.getRow(0), StrEq("A,B,C,D,E"));
}

TEST(FileTable, GetInvalidRow) {

	FileTable ft("../csv/sample.csv");

    ASSERT_THROW(ft.getRow(100), std::out_of_range);
    
}
