/*
题目: 最长有效括号
描述：
给你一个只包含 ‘(’ 和 ‘)’ 的字符串，找出最长有效（格式正确且连续）括号子串的长度

输入：
输入为一个只包含 ‘(’ 和 ‘)’ 的字符串，字符串长度<10000。

输出：
输出为一个数字，表示最长有效括号子串的长度

输入输出样例：

输入
(()
输出
2
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 10000

typedef char ElementType;

typedef struct SqStack
{
    ElementType *base;  
    ElementType *top;
    int stack_size;
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
    {
        char str = 'h';
        return str;
    }
    else
    {
        ElementType *p = S->top-1;
        return *p;
    }
}

int brackets(char str[], SqStack *S, int len)
{
    int i = 0;
    int cet = 0;
    int result = 0;

    char val;

    for(int j =0 ; j<len; j++)
    {
        if(str[i] == '(')
        {
            if(!is_empty(S))
            {
                pop_stack(S, &val);
                cet = 0;  
            }
            val = '(';
            push_stack(S, val);
        }
        else
        {
            if(get_top(S) == '(')
            {
                pop_stack(S, &val);
                // if(is_empty(S))
                // {
                //     cet++;
                // }
                // else
                //     cet = 0;
                cet++;
            }
            // else if(get_top(S) == ')')
            // {
            //     pop_stack(S,&val);
            //     cet = 0;
            // }
            else    //栈是空的
            {
                cet = 0;
            }
        }
        if(result < cet)
            result = cet;
        i++;
    }

    return result*2;
    
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
    printf("%d", brackets(str ,&S, len));
}