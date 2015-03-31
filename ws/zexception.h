#ifndef Z_EXCEPTION_H_
#define Z_EXCEPTION_H_

#include <string>

namespace zws
{

class zexception : public std::exception
{
public:
    zexception(const char* msg="") : msg_(msg) {}

    ~zexception() throw() {}

    const char* what() const throw()
    {
        return msg_.c_str();
    }

private:
    std::string msg_;
};

}

#endif /* Z_EXCEPTION_H_ */
