#include <iostream>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

void format(const char *fmt, ...)
{
     char str[1024] = {0};
     va_list ap;
     va_start(ap, fmt);
     vsnprintf(str, sizeof(str), fmt, ap);
     va_end(ap);

     cout << str << endl;
}

int main()
{
     format("%d %d %d\n", 1, 2, 3);

     return 0;
}


