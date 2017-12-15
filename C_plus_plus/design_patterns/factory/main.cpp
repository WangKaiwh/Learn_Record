#include <iostream>
#include "product.h"
#include "factory.h"

int main()
{
    factory *f = new factory();
    aProduct *p1 = f->get_product(1);	
    p1->operation();

    delete p1;
    p1 = NULL;
	
    p1 = f->get_product(2);
    p1->operation();
	
    delete p1;
    p1 = NULL;
    delete f;
    f = NULL;	
	
    return 0;
}
