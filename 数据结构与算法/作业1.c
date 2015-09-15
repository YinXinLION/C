/*************************************************************************
	> File Name: 作业1.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年09月13日 星期日 16时05分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    int a[7]={1,3,2,7,8,5,9};
    int i ,j ,t;
    for(i = 0;i < 7 - 1 ; i ++)
    for(j = 0;j < 7 - i -1; j++)
    if(a[j] < a[j+1])
    {
        t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
    }

    for(i = 0; i<7;i++)
    printf("%d\n",a[i]);
}
