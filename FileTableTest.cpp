#include "gmock/gmock.h" 
#include <string> 

#include "FileTable.h"

using namespace testing;

class FileTableTest : public Test {
    public:
	    FileTable ft;

	    void SetUp() override {
		    ft.init("../csv/bnumber.csv");
	    }
};

TEST_F(FileTableTest,OffsetsAndLengths) {
    ASSERT_THAT(ft.getNumberOfRows(),Eq(5));
}

TEST_F(FileTableTest, GetRow0) {
	ASSERT_THAT(ft.getRow(0), StrEq("0060,Malaysia"));

}

TEST_F(FileTableTest, GetRow3) {
	ASSERT_THAT(ft.getRow(3), StrEq("006055269705,Silibin"));
}

TEST_F(FileTableTest, GetRow4) {
	ASSERT_THAT(ft.getRow(4), StrEq("0060552,Silibin"));
}

TEST_F(FileTableTest, GetInvalidRowThatIsLargerThanMaxRows) {
    ASSERT_THROW(ft.getRow(5), std::out_of_range);
    
}

TEST_F(FileTableTest, GetInvalidRowThatIsNegative) {
	ASSERT_THROW(ft.getRow(-100), std::out_of_range);
}

TEST_F(FileTableTest,Iterator_ReadTillLastRowUsingForAndPreIncrement) {
    Tokenizer tokens;
	
	for(auto it = ft.begin(); it != ft.end(); ++it) {
		tokens = *it;
	}

	ASSERT_THAT(tokens[0],Eq("0060552"));
}

TEST_F(FileTableTest,Iterator_ReadTillLastRowUsingForAndPostIncrement) {
    std::string line;
    Tokenizer tokens;
	for(auto it = ft.begin(); it != ft.end(); it++) {
		tokens = *it;
	}

	ASSERT_THAT(tokens[0],Eq("0060552"));
}

TEST_F(FileTableTest, Iterator_ForRange) {
    Tokenizer tokens;
    for(auto & currentRow : ft) {
        tokens = currentRow; 
        break;
    } 

    ASSERT_THAT(tokens[0],Eq("0060"));

}
