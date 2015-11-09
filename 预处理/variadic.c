/*************************************************************************
	> File Name: variadic.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月09日 星期一 21时51分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define PR(X,...) printf("Message " #X ": "__VA_ARGS__)

int main(void)
{
    double x =48;
    double y;

    y = sqrt(x);
    PR(1,"x = %g\n",x);
    PR(2,"x = %0.2f,y = %.4f\n",x,y);

    return 0;
}
