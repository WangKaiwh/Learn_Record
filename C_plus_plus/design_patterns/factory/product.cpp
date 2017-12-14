#include <iostream>
#include "product.h"

using namespace std;

//
// 抽象产品实现
aProduct::aProduct() {}
aProduct::~aProduct() {}

//
// 具体产品1实现
product1::product1() {}
product1::~product1() {}

void product1::operation()
{
    cout << "product1 operation called" << endl;
}

//
// 具体产品2实现
product2::product2() {}
product2::~product2() {}

void product2::operation()
{
    cout << "product2 operation called" << endl;
}
