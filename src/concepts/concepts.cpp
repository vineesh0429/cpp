#include "concepts.hpp"
void Mutabletest();
void MutableLambda();
void concepts_test()
{
    // Mutabletest();
    MutableLambda();
}

// mutable keyword
// to change the constentness of

void Mutabletest()
{
    Mutable nonConstVar;
    Mutable const ConstVar;
    // m.setValues(2, 5);
    ConstVar.setValues(150);
    ConstVar.getValues();

    nonConstVar.setValues(2000);
    nonConstVar.getValues();
}

void MutableLambda()
{
    int var_1 = 10;
    int var_2 = 20;
    []()
    {
        std::cout << "Calling lambda function" << std::endl;
    };
}
