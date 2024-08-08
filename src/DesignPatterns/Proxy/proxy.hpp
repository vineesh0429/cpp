#include <iostream>
void proxy_driver();
class Subject
{
public:
    virtual void access() = 0;
};

class RealSubject : public Subject
{
public:
    void access() override
    {
        std::cout << "Access in RealSubject " << std::endl;
    }
};
class Proxy : public Subject
{

    RealSubject *realSubject_;

public:
    Proxy(RealSubject *subject) : realSubject_(subject)
    {

        std::cout << "Proxy created " << std::endl;
    }
    ~Proxy()
    {
        delete realSubject_;
    }
 
    int check_access()
    {
        std::cout << "Checking access in Proxy" << std::endl;
        return true;
    }
    void access() override
    {
        std::cout << "Access in Proxy " << std::endl;
        this->realSubject_->access();
        std::cout<<"Acces via proxy completed"<<std::endl;
    }
};


