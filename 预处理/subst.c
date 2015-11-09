/*************************************************************************
	> File Name: subst.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月09日 星期一 21时36分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PSQR(x) printf("The square of " #x " is %d.\n",((x)*(x)))

int main(void)
{
    int y = 5;

    PSQR(y);
    PSQR( 2 + 4 );
    return 0;
}


