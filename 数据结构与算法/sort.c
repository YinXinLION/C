/*************************************************************************
	> File Name: 直接选择排序法.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月02日 星期一 21时22分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void optionsort(int a[] ,int n);
int main(void)
{
    int i;
    int a[5] = {1 ,3 ,2 ,5 ,4};
    optionsort(a,5);
    for(i = 0;i < 5 ; i++)
    printf("%d  ",a[i]);
    printf("\n");
}

void optionsort(int a[] ,int n)
{
    int i ,j ,k ,temp ;
    for(i = 0;i < n -1 ;i++)
    {
        k = i;
        for(j = i + 1; j < n ; j++)
        {
            if(a[j] < a[k])
            k = j;
        }
        if(i != k)
        {
            temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
}
