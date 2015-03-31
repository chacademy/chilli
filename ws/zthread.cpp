#include "zthread.h"


using namespace zws;

zthread::zthread(
        zrunnable* pRunnable /* = NULL */,
        const char* pName    /* = ""   */)
: zrunnable()
, bStarted_(false)
, thread_()
, pRunnable_(pRunnable)
, name_(pName)
{
}

zthread::~zthread()
{

}

void zthread::start(
        zrunnable* pRunnable /* = NULL */,
        const char* pName    /* = ""   */)
{
    if (bStarted_)
    {
        std::cout<<"Thread already started!"<<std::endl;
        return;
    }

    if (pRunnable)
    {
        pRunnable_ = pRunnable;
    }
    if (!pRunnable_)
    {
        pRunnable = this;
    }
    if (pName)
    {
        name_ = pName;
    }

    create();
    bStarted_ = true;
}

void zthread::join()
{
    int err = pthread_join(thread_, 0);
    if (err != 0)
    {
        throw new zexception("Failed to join thread");;
    }
}

/// private

void zthread::create()
{
    if(pthread_create(&thread_, NULL, &run, pRunnable_) != 0)
    {
        throw new zexception("Failed to create thread");
    }
}

/*static*/
void* zthread::run(void* pRunnable)
{
    reinterpret_cast<zrunnable*>(pRunnable)->run();
    return NULL;
}





