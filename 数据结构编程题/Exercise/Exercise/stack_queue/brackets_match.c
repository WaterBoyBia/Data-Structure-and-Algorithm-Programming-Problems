/*
题目：括号匹配
描述：
使用计算机进行运算时，需要对表达式中括号是否匹配进行检查
例如：(1+2)/(21+9)中括号匹配，(3+2(+(1+2))(2/3中括号不匹配。使用顺序栈实现对表达式中括号是否相匹配的检查。

输入：
一个表达式（长度不超过100）。其中符号中除括号外仅包含 0123456789和加减乘除运算符

输出：
若匹配输出Yes，否则输出No

输入输出样例：
输入 (1+2)/(2*1+9)
输出 Yes

输入 (3+2(+(1+2))*(2/3
输出 False
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 200

typedef char ElementType;

typedef struct SqStack
{
    ElementType *base;  
    ElementType *top;
    ElementType stack_size;
} SqStack;

bool init_stack(SqStack *S)
{
    S->base = (ElementType *)malloc(sizeof(ElementType));
    if(!S->base)
        return false;
    S->top = S->base;
    S->stack_size = MAX_SIZE;
    return true;
}

bool push_stack(SqStack *S, ElementType val)
{
    if(S->top - S->base == S->stack_size)  
        return false;
    else
    {
        *S->top++ = val;   
        return true;
    }
}


bool is_empty(SqStack *S)
{
    if(S->top == S->base)
    {
        return true;
    }
    else
        return false;
}

bool pop_stack(SqStack *S,ElementType *val)
{
    if(is_empty(S))   
        return false;
    else
    {
        ElementType *p = S->top-1;
        *val = *p;
        S->top--;
        return true;
    }
}

ElementType get_top(SqStack *S)
{
    if(is_empty(S))
        return -1;
    else
    {
        ElementType *p = S->top-1;
        return *p;
    }
}

void brackets_match(char str[], SqStack *S)
{
    bool status = true;
    int i = 0;

    while(str[i] != '\0' && status == true)
    {
        if(str[i] == '(')
        {
            char temp = str[i];
            push_stack(S, temp);
        }  
        else if(str[i] == ')')
        {
            if(is_empty(S))
            {
                status = false;
            }
            else 
            {
                char c;
                pop_stack(S, &c);
            }
        }
        i++;
    }

    if(is_empty(S) && status==true)
        printf("Yes");
    else
        printf("False");
}

void main()
{
    char *p = NULL;
    p = (char *)malloc(sizeof(char));
    scanf("%s", p);
    int len = strlen(p);
    char str[len];
    for (int i = 0; i < len; i++)
    {
        str[i] = *p;
        p++;
    }
    SqStack S;
    init_stack(&S);
    brackets_match(str, &S);
}
