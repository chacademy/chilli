#include "verifycode.h"

#include <ctime>
#include <cstdlib>

using namespace std;

namespace utils {

string VerifyCode::generate(int len)
{
    string ret;
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        int pos = rand() % digits_alphabet_len;
        ret.push_back(digits_alphabet[pos]);
    }
    return ret;
}

}
