#ifndef AUTH_USER_H_ 
#define AUTH_USER_H_

#include <string>

using namespace std;

namespace auth {

class User
{
public:
    int id;
    int sex; // -1:unkown, 0:female, 1:male
    string name;
    string nickname;
    string password;
    string email;
    string phone;

public:
    User();
};

}

#endif
