#include "ZWebServer.h"

#include <sys/select.h>

namespace zws{

ZWebServer::ZWebServer()
:stopFlag_(false)
{

}

void init()
{

}

void ZWebServer::start()
{
    fd_set      read_set;
    struct timeval  tv;
    int     i, max_fd;

    while (!stopFlag_)
    {
        FD_ZERO(&read_set);
        max_fd = -1;

        //xxx lock_option
        for (i = 0; i < ctx_.num_listeners; i++)
        {
            sockfd_t fd = ctx_.listeners[i].sockFd_;
            FD_SET(fd, &read_set);
            if (fd > (sockfd_t) max_fd)
            {
                max_fd = (int) fd;
            }
        }
        //unlock_option
    }

}

}
