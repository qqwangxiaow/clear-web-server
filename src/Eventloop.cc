
#include "Eventloop.h"
#include<iostream>
__thread Eventloop* isLoopInthisThread=nullptr
//__thread变量每一个线程有一份独立实体
Eventloop::Eventloop()
    :isLooping(false),
    threadID(CurrentThread::tid())
{
    std::cout<<"eventloop created"<<this<<"in thread"<<threadID;
    if(isLoopInthisThread)
    {
        std::cout<<"Another eventloop "<<isLoopInthisThread<<"exists in this thread"<<threadID;
    }
    else
    {
        isLoopInthisThread=this;
    }

}

Eventloop::~Eventloop()
{
    assert(!isLooping);
    isLoopInthisThread=nullptr;

}

void Eventloop::loop()
{
    assert(!isLooping);
    assert(isInLoopThread());
    isLooping=true;
    poll(nullptr,0,5*1000);
    std::cout<<"eventloop"<<this<<"stop looping";
    isLooping=false;=
}