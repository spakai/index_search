#include "RegexTokenizer.h"

void RegexTokenizer::tokenize(const string& csvrow) {
#if GCC_VERSION > 40803
    regex re("[,]+");
    sregex_token_iterator it(csv.begin(), csv.end(), re, -1);
    copy(it,sregex_token_iterator(), back_inserter(tokens)); 
#endif
}
