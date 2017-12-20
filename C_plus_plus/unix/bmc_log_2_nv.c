
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

// wangkai add
static int fetch_file_size(FILE* fp)
{
    int pos;
    int size;
    
    assert(fp);

    pos = ftell(fp);

    fseek(fp, 0, SEEK_END);

    size = ftell(fp);

    fseek(fp, pos, SEEK_SET);
    
    return size;
}

// wangkai temp
static void fh_printf(const char *str)
{
    assert(str);

    FILE *fp = fopen("/nv/printf-log", "a+");
    assert(fp);

    // in case of /nv section full !
    if (fetch_file_size(fp) + strlen(str) < 1024*1024) 
        fwrite(str, 1, strlen(str), fp);
    else
        ; // todo 

    fclose(fp);
}

static void fh_printf(const char *fmt, ...)
{

    char str[1024] = {0};
    va_list ap;

    assert(fmt);

    va_start(ap, fmt);
    int r = vsnprintf(str, sizeof(str), fmt, ap);
    va_end(ap);

    if (r < 0) 
        return;

    FILE *fp = fopen("/nv/printf-log", "a+");
    assert(fp);

    // in case of /nv section full !
    if (fetch_file_size(fp) + strlen(str) < 1024*1024) 
        fwrite(str, 1, strlen(str), fp);
    else
        ; // todo 

    fclose(fp);
}

// g++ compile
int main()
{
    fh_printf("%d %d %d\n", 1, 2, 3);

    return 0;
}


