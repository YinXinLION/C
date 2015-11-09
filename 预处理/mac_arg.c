/*************************************************************************
	> File Name: mac_arg.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月09日 星期一 21时18分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n",X)
int main(void)
{
    int x = 4;
    int z;

    printf("x = %d\n",x); //==>4
    z = SQUARE(x); //z = 16
    printf("Evaluating SQUARE(x):");
    PR(z); //==>16
    z = SQUARE(2);// z = 4
    printf("Evaluating SQUARE(x+2)");
    PR(SQUARE(x+2));//x = 4 ==> x+2*x+2 ==> 4 + 8 + 2 ==> 14
    printf("Evaluating 100/SQUARE(2):");
    PR(100/SQUARE(2));//100/2*2 ==> 100
    printf("x is %d.\n",x);//==>4
    printf("Evaluating SQUARE(++x)");
    PR(SQUARE(++x));//==>++x*++x ==> 5 * 6 ==> 30
    printf("After incrementing, x is %d.\n",x); ==> 6

    return 0;
}
