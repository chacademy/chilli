/**
 * @file zthread.h
 * @author Zhongxia Li
 * @date Dec 21, 2011
 * @brief 
 */
#ifndef Z_THREAD_H_
#define Z_THREAD_H_

#include "zexception.h"

#include <errno.h>

extern "C"
{
#include <pthread.h>
}

#include <iostream>
#include <string>

namespace zws{

class zrunnable
{
public:
    virtual void run() = 0;

protected:
    zrunnable() {}
    virtual ~zrunnable() {}
};

class zthread : public zrunnable
{
public:
    zthread(
        zrunnable* pRunnable = NULL,
        const char* pName = "");

    virtual ~zthread();

    void start(
            zrunnable* pRunnable = NULL,
            const char* pName = "");

    void join();

private:
    void create();

    static void* run(void* pRunnable);

private:
    bool        bStarted_;
    pthread_t   thread_;
    zrunnable*  pRunnable_;
    std::string name_;
};

class zmutex
{
public:
    zmutex(const pthread_mutexattr_t *attr = NULL)
    {
        pthread_mutex_init(&mutex_, attr);
    }

    /**
     * zmutex in specified type
     * @param kind
     * PTHREAD_MUTEX_NORMAL
     * PTHREAD_MUTEX_RECURSIVE
     * PTHREAD_MUTEX_ERRORCHECK
     * PTHREAD_MUTEX_DEFAULT
     */
    zmutex(int kind)
    {
        pthread_mutexattr_t attr;
        pthread_mutex_init(&mutex_, &attr);
        pthread_mutexattr_settype(&attr, kind);
        pthread_mutex_init(&mutex_, &attr);
    }

    ~zmutex()
    {
        pthread_mutex_destroy(&mutex_);
    }

public:
    void lock()
    {
        int err = pthread_mutex_lock(&mutex_);
        if (err != 0) { throw zexception("failed to lock thread mutex"); }
    }

    bool trylock()
    {
        int err = pthread_mutex_trylock(&mutex_);

        if (err != 0) {
            if (err == EBUSY)
                return false;
            else
                throw zexception("failed to trylock thread mutex");
        }
        return true;
    }

    void unlock()
    {
        int err = pthread_mutex_unlock(&mutex_);
        if (err != 0) { throw zexception("failed to unlock thread mutex"); }
    }

public:
    pthread_mutex_t* get() { return &mutex_; }

private:
    pthread_mutex_t mutex_;

private:
    zmutex(const zmutex&);
    zmutex& operator = (const zmutex&);
};


}

#endif /* Z_THREAD_H_ */
