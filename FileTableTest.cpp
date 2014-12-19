#include "gmock/gmock.h" 
#include <string> 

#include "FileTable.h"

using namespace testing;

TEST(FileTable,OffsetsAndLengths) {

	FileTable ft("../csv/sample.csv");
 
    ASSERT_THAT(ft.getNumberOfRows(),Eq(5));
}
