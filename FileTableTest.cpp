#include "gmock/gmock.h" 
#include <string> 

#include "FileTable.h"

using namespace testing;

TEST(FileTable,OffsetsAndLengths) {

	FileTable ft("../csv/sample.csv");
 
    ASSERT_THAT(ft.getNumberOfRows(),Eq(5));
}

TEST(FileTable, GetRow0) {
	
	FileTable ft("../csv/sample.csv");

	ASSERT_THAT(ft.getRow(0), StrEq("A,B,C,D,E"));

}

TEST(FileTable, GetRow3) {
	
	FileTable ft("../csv/sample.csv");

	ASSERT_THAT(ft.getRow(3), StrEq("Z,YX,AB,DE,GH"));

}

TEST(FileTable, GetRow4) {
	
	FileTable ft("../csv/sample.csv");

	ASSERT_THAT(ft.getRow(4), StrEq("12,DF,ER,AD,JK"));

}

TEST(FileTable, GetInvalidRowThatIsLargerThanMaxRows) {

	FileTable ft("../csv/sample.csv");

    ASSERT_THROW(ft.getRow(5), std::out_of_range);
    
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

TEST(TableIterator,ReadLastRow) {

    std::string line; 

    FileTable ft("../csv/sample.csv");

    FileTable::Iterator end ; 

    FileTable::Iterator begin(ft);

    std::for_each(begin,end, [&line](const std::string& record){ line = record; });

    ASSERT_THAT(line,Eq("12,DF,ER,AD,JK"));

}
