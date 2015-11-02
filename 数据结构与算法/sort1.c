/*************************************************************************
	> File Name: 直接插入排序法.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月02日 星期一 20时53分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void Insertsort(int a[] , int n);


int main(void)
{
    int i;
    int a[5] = {4 ,2 ,6 ,8 ,9};
    Insertsort(a ,5);
    for(i = 0; i < 5 ;i++)
    printf("%d  ",a[i]);
    printf("\n");
}

void Insertsort(int a[] , int n)
{
    int i ,j ,temp;
    for(i = 1;i < n; i++)
    {
        temp = a[i];
        for(j = i - 1; j >= 0 && (a[j] > temp) ;j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}













