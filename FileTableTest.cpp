#include "gmock/gmock.h" 
#include <string> 

#include "FileTable.h"

using namespace testing;

TEST(FileTable,OffsetsAndLengths) {

	FileTable ft("../csv/bnumber.csv");
 
    ASSERT_THAT(ft.getNumberOfRows(),Eq(5));
}

TEST(FileTable, GetRow0) {
	
	FileTable ft("../csv/bnumber.csv");

	ASSERT_THAT(ft.getRow(0), StrEq("0060,Malaysia"));

}

TEST(FileTable, GetRow3) {
	
	FileTable ft("../csv/bnumber.csv");

	ASSERT_THAT(ft.getRow(3), StrEq("006055269705,Silibin"));

}

TEST(FileTable, GetRow4) {
	
	FileTable ft("../csv/bnumber.csv");

	ASSERT_THAT(ft.getRow(4), StrEq("0060552,Silibin"));

}

TEST(FileTable, GetInvalidRowThatIsLargerThanMaxRows) {

	FileTable ft("../csv/bnumber.csv");

    ASSERT_THROW(ft.getRow(5), std::out_of_range);
    
}

TEST(FileTable, GetInvalidRowThatIsNegative) {

	FileTable ft("../csv/bnumber.csv");

    ASSERT_THROW(ft.getRow(-100), std::out_of_range);
    
}

TEST(TablIterator, Iterator) {

    FileTable ft("../csv/bnumber.csv");

    FileTable::Iterator end ; 

    FileTable::Iterator begin(ft);

    int numberOfRows=0;

    std::for_each(begin,end, [&numberOfRows](const std::string& record){ ++numberOfRows; });
     
    ASSERT_THAT(numberOfRows,Eq(5));

}

TEST(TableIterator,ReadLastRow) {

    std::string line; 

    FileTable ft("../csv/bnumber.csv");

    FileTable::Iterator end ; 

    FileTable::Iterator begin(ft);

    std::for_each(begin,end, [&line](const std::string& record){ line = record; });

    ASSERT_THAT(line,Eq("0060552,Silibin"));

}
