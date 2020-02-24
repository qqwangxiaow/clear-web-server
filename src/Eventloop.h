//
// Created by 王晓威 on 2020/1/18.
//

#ifndef PROJECT_EVENTLOOP_H
#define PROJECT_EVENTLOOP_H

#endif //PROJECT_EVENTLOOP_H
#include"base/CurrentThread.h"
class Eventloop
{

public:
    Eventloop(/* args */);
    ~Eventloop();
    void loop();
    bool isInLoopThread() const{
        return threadID==CurrentThread::tid();
    }
private:
    bool isLooping;
    const pid_t threadID;
    
};


