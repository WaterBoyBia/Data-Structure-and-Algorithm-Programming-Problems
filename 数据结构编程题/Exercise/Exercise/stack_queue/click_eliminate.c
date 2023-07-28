/*
题目: 点击消除
描述：
给定一个字符串，每次“点击”，可以把字符串中相邻两个相同字母消除，例如，字符串"abbc"点击后可以生成"ac"。但相同而不相邻、不相同的
相邻字母都是不可以被消除的。
通过点击足够多次之后可以把字符串变得尽可能短，编程实现输出给定字符串足够多次点击后的最终形态。

输入：
一个字符串，仅由小写字母组成。（字符串长度不大于10000）

输出：
一个字符串，为“点击消除”后的最终形态。若最终的字符串为空串，则输出0。

输入输出样例：
输入 abbc
输出 ac
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 10001

typedef char ElementType;

typedef struct SqStack
{
    ElementType *data;
    int capacity;
    int size;
} SqStack;

void init_stack(SqStack *S)
{
    S->data = (ElementType *)malloc(sizeof(ElementType) * MAX_SIZE);
    S->capacity = MAX_SIZE;
    S->size = 0;
}

bool is_full(SqStack *S)
{
    if(S->size >= S->capacity)
    {
        return true;
    }
    else
        return false;
}

bool push_stack(SqStack *S, ElementType val)
{
    if(is_full(S))  //判断是否栈满
        return false;
    else
    {
        S->data[S->size] = val;
        S->size += 1;
        return true;
    }
}


void traverse_stack(SqStack *S)
{
    for(int i=0; i< S->size; i++)
    {
        printf("%c",S->data[i]);
    }
}

bool is_empty(SqStack *S)
{
    if(S->size == 0)
    {
        return true;
    }
    else
        return false;
}

bool pop_stack(SqStack *S,ElementType *val)
{
    if(is_empty(S))   //判断是否栈空
        return false;
    else
    {
        *val = S->data[S->size-1];
        S->size -= 1;
        return true;
    }
}

ElementType get_top(SqStack *S)
{
    if(is_empty(S))
    {
        char a = 'A';
        return a;
    }
    else
    {
        ElementType val;
        val = S->data[S->size-1];
        return val;
    }
    
}

void eliminate(SqStack *S, char str[], int len)
{
    int i =0;
    while (/*str[i] != '\0'*/i<len)
    {
        if(str[i] != get_top(S))
            push_stack(S, str[i]);
        else
        {
            char s;
            pop_stack(S, &s);
        }
        i++;
    }
    
}

void main()
{
    SqStack S;
    init_stack(&S);
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
    printf("%s",str);
    eliminate(&S, str, len);
    if(is_empty(&S))
        printf("0");
    else
        traverse_stack(&S);
}

