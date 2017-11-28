#include <stdio.h>
#define __DEBUG__  
#ifdef __DEBUG__  
//#define DEBUG(format,...) printf("File: "__FILE__", Line: %05d: "format"\n", __LINE__, ##__VA_ARGS__)  
#define DEBUG(format,...) printf(__FILE__"(%s:%d)"format, __FUNCTION__, __LINE__, ##__VA_ARGS__)  
#else  
#define DEBUG(format,...)  
#endif  
int main() {  
    char str[]="Hello World";  
    DEBUG("%s\n",str); // define_printf.c(main:11)Hello World  
    return 0;  
}  
