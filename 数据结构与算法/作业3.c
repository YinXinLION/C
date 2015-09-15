/*************************************************************************
	> File Name: 作业3.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年09月14日 星期一 17时46分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[7] = {10,10,3,9,8,6,7};
    int i;
    int max,min;
    max = min = 0;
    for(i = 1;i < 7; i++)
    {
        if(a[max] < a[i])
        {
            min = max;
            max = i;
            continue;
        }
        else if(i == 1&& a[max] > a[i])
        {
            min = i;
        }
        if(a[min] < a[i])
        {
            min = i;
        }
    }

    printf("%d %d",a[max],a[min]);
}
