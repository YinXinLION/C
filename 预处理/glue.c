/*************************************************************************
	> File Name: glue.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月09日 星期一 21时41分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define XNAME(n) x##n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);

int main(void)
{
    int XNAME(1) = 14; //变为int x1 = 14;
    int XNAME(2) = 20;//变为int x2 = 20;
    PRINT_XN(1); //变为printf("x1 = %d\n",x1);
    PRINT_XN(2); //变为printf("x2 = %d\n",x2);

    return 0;
}
