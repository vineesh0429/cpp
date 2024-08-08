#include <iostream>

void concepts_test();

class Mutable
{
    const int var_1 = 5;
    mutable int var_2 = 10;
    int var_3 = 100;
    const int mutconstint = 10;

public:
    void setValues(int a, int b)
    {
        var_2 = a;
        var_3 = b;
    }
    void setValues(int a) const
    {
        std::cout << "const memeber function called " << std::endl;
        var_2 = a;
    }
    void getValues() const
    {
        std::cout << "var_1 :" << var_1 << std::endl;
        std::cout << "var_2 :" << var_2 << std::endl;
        std::cout << "var_3:" << var_3 << std::endl;
    }
};