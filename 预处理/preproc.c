/*************************************************************************
	> File Name: preproc.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月09日 星期一 21时10分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//简单的预处理器的例子
#define TWO 2
#define OW "Consistency is the last refuge of the unimagina\
tive. -Oscar Wilde" //反斜线把这个定义延续到下一行
#define FOUR TWO*TWO
#define PX printf("X is %d.\n",x)
#define FMT "X is %d.\n"

int main(void)
{
    int x = TWO;

    PX;
    x = FOUR;
    printf(FMT,x);
    printf("%s\n",OW);
    printf("TWO:OW\n");
    return 0;
}

