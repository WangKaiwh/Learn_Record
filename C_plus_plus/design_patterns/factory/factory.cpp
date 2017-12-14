#include <iostream>
#include "product.h"
#include "factory.h"

using namespace std;

aFactory::aFactory() {}
aFactory::~aFactory() {}

factory::factory() {}
factory::~factory() {}

aProduct* factory::get_product(int type)
{
    switch (type)
    {
    case 1: return new product1();
    case 2: return new product2();
    default: 
        cout << "unknown type" << endl;
        return NULL;
    }
}


