/**
 * @file   ZWebServer.h
 * @author Zhong-Xia Li
 * @date   Dec 5, 2011
 * @brief
 */

#ifndef Z_WEB_SERVER_H_
#define Z_WEB_SERVER_H_

#include "ZWSContext.h"

namespace zws{

class ZWebServer
{
public:
    ZWebServer();

    void init();

    void start();

private:
    bool stopFlag_;

    ZWSContext ctx_;
};

}

#endif /* Z_WEB_SERVER_H_ */
