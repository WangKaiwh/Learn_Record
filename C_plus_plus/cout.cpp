#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    unsigned char *p = nullptr;
    unsigned char v = 0x33;

    p = &v;

    cout << "*p val =  " << *p << endl;
    printf("*p val = %#x\n", *p);

    unsigned int *pint = nullptr;
    unsigned int  vint = 0x33;

    pint = &vint;
    cout <<"*pint val = " << *pint << endl;
    printf("*pint val = %u\n", *pint);

    return 0;
}
