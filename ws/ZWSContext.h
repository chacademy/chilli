/**
 * @file   ZWSContext.h
 * @author Zhong-Xia Li
 * @date   Dec 5, 2011
 * @brief
 */

#ifndef ZWS_CONTEXT_H_
#define ZWS_CONTEXT_H_

namespace zws{

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

typedef int sockfd_t;

struct usa_t {
    socklen_t len;
    union {
        struct sockaddr sa;
        struct sockaddr_in sin;
    } u;
};

struct socket_t {
    sockfd_t          sockFd_;       /* Listening socket     */
    struct usa_t    lsa;        /* Local socket address     */
    struct usa_t    rsa;        /* Remote socket address    */
};


static const int MAX_LISTENING_SOCKETS = 5;

struct ZWSContext
{
    int num_listeners;
    struct socket_t listeners[MAX_LISTENING_SOCKETS];
};

}

#endif /* ZWS_CONTEXT_H_ */
