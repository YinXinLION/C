/*************************************************************************
	> File Name: 一元多项式.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年09月19日 星期六 21时32分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct polynomail
{
    int    coef; //系数
    int    expn; //指数
    struct polynomail *next;
}poly;

poly *createpoly();
poly *creatnode();
void poly_operation(poly *headpa ,poly *headpb);
void print_poly(poly *head ,char *name);
poly *add_poly(poly *headpa ,poly *headpb);
int main()
{
    poly *headpa ,*headpb;
    headpa = createpoly();
    headpb = createpoly();
    poly_operation(headpa ,headpb);
    headpa = add_poly(headpa ,headpb);
    print_poly(headpa ,"pa");

    return 0 ;
}

poly *createpoly()
{
    poly *head ,*p ,*q;
    char flag;
    int c;
    head = p = creatnode();
    printf("Please input:\n");
    while(1)
    {    
        q = (poly *)malloc(sizeof(poly));
        scanf("%d,%d",&q->coef,&q->expn);
        setbuf(stdin,NULL);
        p -> next = q;
        p = q;
        printf("是否继续创建:(y/n)");
        scanf("%c",&flag);
        do{
            c = fgetc(stdin);
        } while (c != '\n' && c != EOF);
        if(flag == 'n')
        {
            break;
        }
        else
        continue;
    }
    return head;
}

poly *creatnode()
{
    poly *head;
    head = (poly *)malloc(sizeof(poly));
    head -> next = NULL;
    return head;
}

void print_poly(poly *head ,char *name)
{
    poly *q;
    q = head->next;
    printf("        %s = ",name);
    while(1)
    {
        if(q -> expn == 0)
        printf("%d",q -> coef);
        else if(q -> expn == 1)
        printf("%dX",q ->expn);
        else if(q -> expn > 1)
        printf("%dX^%d",q->coef ,q->expn);


        if(q -> next == NULL)
        break;
        q = q -> next;
        printf("+");
    }
    printf("\n");
}

void poly_operation(poly *headpa,poly *headpb)
{
    char name;
    int c; 
    printf("Please select your Opteration : ");
    setbuf(stdin,NULL);
    scanf("%c",&name);
        do{
            c = fgetc(stdin);
        } while (c != '\n' && c != EOF);
    if(name == 'a')
    {
        print_poly(headpa ,"pa");
    }
    else if(name == 'b')
    {
        print_poly(headpb ,"pb");
    }
    else
    {
        printf("没有想要的多项式\n");
    }
}

poly *add_poly(poly *headpa ,poly *headpb)
{
    poly *pa ,*pb;
    poly *headpc ,*p ,*t ,*y;
    pa = headpa -> next;
    pb = headpb;

    for(y = pa; y != NULL; y = y -> next)
    {
        for(t = pb; t -> next!= NULL ;t = t -> next)
        {
            if(y -> expn == t -> next -> expn)
            {
                y -> expn = y -> expn + t -> next -> expn;
                y -> coef = y -> coef + t -> next -> coef;
                p = t -> next;
                t -> next = p -> next;
                free(p);
                break;
            }
        }
    }
    printf("%d %d",headpa -> next -> coef ,headpa -> next -> expn);
    if(headpb -> next !=  NULL)
    {
        y = headpa;
        while(1)
        {
            if(y -> next == NULL)
            break;
            y = y -> next;
        }
    }
    y -> next = headpb -> next;

   return headpa;
}













