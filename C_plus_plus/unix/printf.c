
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void fh_printf(const char *str)
{
    assert(str);

    FILE *fp = fopen("printf-log", "a+");
    assert(fp);

    fwrite(str, 1, strlen(str), fp);

    fclose(fp);
}

int main()
{
    fh_printf("Hello world.\n");

    fh_printf("111111111\n");

    fh_printf("222222222\n");

    return 0;
}

