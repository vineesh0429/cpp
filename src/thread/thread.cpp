#include "thread.hpp"
#include <chrono>
constexpr int32_t thread_wait_time = 1;
constexpr int32_t main_thread_waiting_time = 1;

void thread_funcA();

void thread_test_func()
{
    // data_race_test();
    // thread_unordered_test();
    mainthradfun();
}
// Program to print current time in every 1 milisecond , while main thread sleeps for 1 second

void thread_fun()
{
    auto start = std::chrono::system_clock::now();
    while (std::chrono::system_clock::now() - start < std::chrono::seconds(thread_wait_time))
    {
        static int count = 0;
        const auto time_now = std::chrono::system_clock::now();
        const auto time_now_print = std::chrono::system_clock::to_time_t(time_now);
        std::cout << " Time :" << count++ << ":" << time_now_print << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(thread_wait_time));
    }
}

void print_time()
{
    std::thread t(thread_fun);
    std::this_thread::sleep_for(std::chrono::seconds(main_thread_waiting_time));
    t.join();
    std::cout << "Main threrad exiting" << std::endl;
}

// Data race

void hello()
{
    std::cout << "Hellow " << std::endl;
}

void data_race_test()
{

    std::thread ts[50];
    for (std::thread &t : ts)
    {
        t = std::thread(hello);
    }
    for (std::thread &t : ts)
    {
        t.join();
    }
}

// threads are unordered

void thread_func(int i)
{
    std::cout << "Hello :" << i << std::endl;
}
void thread_unordered_test()
{
    std::thread ts[10];
    for (int i = 0; i < 10; i++)
    {
        ts[i] = std::thread(thread_func, i);
    }
    for (int i = 0; i < 10; i++)
    {
        ts[i].join();
    }
}

// Launching thread

void thread_funcA()
{
    std::cout << "Hello from thread_funcA:" << std::this_thread::get_id() << std::endl;
}

void mainthradfun()
{
    ThreadFun obj;
    std::thread thread1(thread_funcA);
    std::thread thread2(obj);
    std::thread thread3([]()
                        { std::cout << " Hello from thread lambda " << std::endl; });
    thread1.join();
    thread2.join();
    thread3.join();
}

// Thread Join
void thread_func_C()
{
    std::cout << "Hellow from thread_func_C" << std::endl;
}

void threadJoinTest()
{
}
