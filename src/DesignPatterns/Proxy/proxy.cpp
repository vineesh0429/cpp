/*Proxy is a structural design pattern that provides an object that acts as a substitute for a real service object used by a client.
A proxy receives client requests, does some work (access control, caching, etc.) and then passes the request to a service object.

*/
#include "proxy.hpp"
void ClientCode(Subject *subject);

void proxy_driver()
{
    std::cout << "Without using proxy" << std::endl;
    RealSubject *realsunject = new RealSubject();
    ClientCode(realsunject);
    std::cout << "----------------" << std::endl;

    std::cout << "Using proxy " << std::endl;
    Proxy *proxy = new Proxy(realsunject);
    ClientCode(proxy);
    std::cout << "----------------" << std::endl;
}

void ClientCode(Subject *subject)
{
    subject->access();
}