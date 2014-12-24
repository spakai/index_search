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

TEST(FileTable, GetInvalidRowThatIsLargerThanMaxRows) {

	FileTable ft("../csv/sample.csv");

    ASSERT_THROW(ft.getRow(100), std::out_of_range);
    
}

TEST(FileTable, GetInvalidRowThatIsNegative) {

	FileTable ft("../csv/sample.csv");

    ASSERT_THROW(ft.getRow(-100), std::out_of_range);
    
}

TEST(FileTable, Iterator) {

    FileTable ft("../csv/sample.csv");

    FileTable::Iterator end ; 

    FileTable::Iterator begin(ft);

    int numberOfRows=0;

    std::for_each(begin,end, [&numberOfRows](const std::string& record){ ++numberOfRows; });
     
    ASSERT_THAT(numberOfRows,Eq(5));

}
