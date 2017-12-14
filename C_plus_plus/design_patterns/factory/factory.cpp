#include <iostream>
#include "product.h"
#include "factory.h"

using namespace std;

//
// 抽象工厂实现
aFactory::aFactory() {}
aFactory::~aFactory() {}

//
// 具体工厂实现
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


