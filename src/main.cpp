#include "DesignPatterns/Proxy/proxy.hpp"
#include "thread/thread.hpp"
#include "concepts/concepts.hpp"

int main()
{

    std::cout << "===Main function=====" << std::endl;
    thread_test_func();
    concepts_test();
}