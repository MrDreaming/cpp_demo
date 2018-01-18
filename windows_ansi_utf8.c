#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
#include <windows.h>    
#include <assert.h>    
#include <locale.h>   
#include <iostream>  
  
using namespace std;  
  
char* Unicode2Utf8(const char* unicode)    
{    
    int len;    
    len = WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)unicode, -1, NULL, 0, NULL, NULL);    
    char *szUtf8 = (char*)malloc(len + 1);    
    memset(szUtf8, 0, len + 1);    
    WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)unicode, -1, szUtf8, len, NULL,NULL);    
    return szUtf8;    
}    
    
char* Ansi2Unicode(const char* str)    
{    
    int dwUnicodeLen = MultiByteToWideChar(CP_ACP,0,str,-1,NULL,0);    
    if(!dwUnicodeLen)    
    {    
        return _strdup(str);    
    }    
    size_t num = dwUnicodeLen*sizeof(wchar_t);    
    wchar_t *pwText = (wchar_t*)malloc(num);    
    memset(pwText,0,num);    
    MultiByteToWideChar(CP_ACP,0,str,-1,pwText,dwUnicodeLen);    
    return (char*)pwText;    
}    
    
char* ConvertAnsiToUtf8(const char* str)    
{    
    char* unicode = Ansi2Unicode(str);     
    char* utf8 = Unicode2Utf8(unicode);    
    free(unicode);    
    return utf8;    
}    
  
wchar_t * UTF8ToUnicode( const char* str )  
{  
     int textlen ;  
     wchar_t * result;  
     textlen = MultiByteToWideChar( CP_UTF8, 0, str,-1, NULL,0 );   
     result = (wchar_t *)malloc((textlen+1)*sizeof(wchar_t));   
     memset(result,0,(textlen+1)*sizeof(wchar_t));   
     MultiByteToWideChar(CP_UTF8, 0,str,-1,(LPWSTR)result,textlen );   
     return result;   
}  
    
int main(int argc, char *argv[])    
{    
    printf("测试开始\n");    
  
    //构造“abc”   
    char ansi[] = {0x61,0x62,0x63,0};    
    char utf8[] = {0x61,0x62,0x63,0};    
  
    //ANSI-->UTF8  
    char* utf8_str = ConvertAnsiToUtf8(ansi);    
    if(strcmp(ansi,utf8_str) == 0)  
    {  
        printf("转换成功\n\n");  
        printf("%s\n",utf8_str);  
    }  
  
    //UTF-8-->Unicode  
     wchar_t* unicodeStr = UTF8ToUnicode(utf8_str);   
     if(unicodeStr != NULL)  
     {  
         std::wcout << unicodeStr << endl;  
     }  
     if(NULL != utf8_str)  
        free(utf8_str);   
  
     if(NULL != unicodeStr)  
         free(unicodeStr);  
  
    system("pause");  
    return 0;    
} 