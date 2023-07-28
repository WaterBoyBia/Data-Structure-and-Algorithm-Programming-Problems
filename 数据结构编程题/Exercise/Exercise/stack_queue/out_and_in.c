/*
题目: 入栈与出栈
描述：
给定一个正整数数列（以0表示输入结束），从第一个数开始，将每一个数入栈，入栈的同时获得一个分数，即该数的数值乘以入栈后栈的大小，请计算将所有元素入栈后的分数和，然后将栈内元素依次输出，要求使用顺序栈。元素个数<100，每个元素<100。

输入：
一行，一个正整数数列，以0结尾。

输出：
两行，第一行为一个正整数，表示分数和。
第二行为将所有元素出栈后的结果，空格分隔

输入输出样例：
输入 5 4 3 2 1 0
输出
35
1 2 3 4 5
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 200

typedef int ElementType;

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
    int temp = S->size;
    while(temp != 0)
    {
        printf("%d ",S->data[temp-1]);
        temp--;
    }
    printf("\n");
}

void function()
{
    SqStack S;
    init_stack(&S);

    ElementType n;
    int sum = 0;
    scanf("%d", &n);

    SqStack *p = &S;
    while(n != 0)
    {
        push_stack(&S, n);
        sum = sum + n*(p->size);
        scanf("%d", &n);
    }

    printf("%d\n",sum);
    traverse_stack(&S);
}

void main()
{
    function();
}