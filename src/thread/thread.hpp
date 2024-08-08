#include <iostream>
#include <thread>

void thread_fun();
void print_time();
void thread_test_func();
void data_race_test();
void thread_unordered_test();
void mainthradfun();

class ThreadFun
{
public:
    void operator()()
    {
        std::cout << "This is ThreadFun operator" << std::endl;
    }
};
