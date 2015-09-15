/*************************************************************************
	> File Name: 作业2.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年09月13日 星期日 23时14分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i;
    int a[7] = {9,2,5,7,6,8,10};
    int max;
    int t;
    max = 0;
    for(i = 1; i < 7;i++)
    {
        if(a[max] < a[i])
        max = i;
    }
    t = a[max];
    for(i = max;i < 7; i++)
    {
        a[i] = a[i+1];
    }
    
    for(i =0 ;i < 7 -1;i++)
    {
        if(a[max] < a[i])
        max = i;
    }
    printf("%d %d\n",t,a[max]);
}
