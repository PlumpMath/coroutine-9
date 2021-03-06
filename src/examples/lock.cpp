/*
 * lock.cpp
 *
 *  Created on: 2015年7月6日
 *      Author: zhusheng
 */
#include "couv/lock.h"
#include "log/Logger.h"
#include "iostream"

#include "couv/coroutine.h"
#include "couv/scheduler.h"

using namespace couv;

int main()
{
    Logger::logger().setDevice(NULL);

    scheduler_t scheduler;
    std::cout << "hello world 0\n";

    lock_t lock;
    lock.lock();
    go{
            std::cout << "hello world 1.1\n";
            lock.lock();
            std::cout << "hello world 1.2\n";
    };
    go{
            std::cout << "hello world 2.1\n";
            lock.unlock();
            std::cout << "hello world 2.2\n";
    };
    scheduler.run();
    return 0;
}



