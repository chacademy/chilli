#include <string>

using namespace std;


namespace utils {

static const string digits_alphabet =  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const int digits_len = 10;
static const int digits_alphabet_len = digits_alphabet.size();

class VerifyCode
{
public:
    static string generate(int len);
};

}
