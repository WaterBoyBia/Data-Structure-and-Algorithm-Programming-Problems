/*
题目: 栈的操作
描述：
请你实现一个栈。
可以完成操作：
push x：将 x入栈，保证 x为 int 型整数。
pop：输出栈顶，并让栈顶出栈
top：输出栈顶，栈顶不出栈

输入：
第一行为一个正整数 n，代表操作次数。(1≤n≤10000)
接下来的 n行 ，每行为一个字符串，代表一个操作。保证操作是题目描述中三种中的一种。

输出：
如果操作为push，则不输出任何东西。
如果为另外两种，若栈为空，则输出 "error"
否则按对应操作输出。

输入输出样例：

输入
6
push 1
pop
top
push 2
push 3
pop

输出
1
error
3
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef int ElementType;

typedef struct StackNode              
{
    ElementType data;
    struct StackNode *next;
} StackNode, *Stack;

Stack init_stack()
{
    StackNode *S;
    S = (StackNode *)malloc(sizeof(StackNode));
    S->next = NULL;
    return S;
}

void push_stack(StackNode *S , ElementType val)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = val;
    newNode->next = S->next;
    S->next = newNode;
}

bool is_empty(StackNode *S)
{
    if(S->next == NULL)
		return true;
	else
		return false;
}

bool pop_stack(StackNode *S, ElementType *val)
{
    if(is_empty(S)) 
	    return false;
    else
    {
        StackNode *p = S->next;
        *val = p->data;
        S->next = p->next;
        free(p);
        p = NULL;

        return true;
    }
}

ElementType get_top(StackNode *S)
{
    StackNode *p = S->next;
    return p->data;
}

void operate(StackNode *S)
{
    int num;
    scanf("%d", &num);

    char order[5] = {};
    char pop[] = "pop";
    char push[] = "push";
    char top[] = "top";

    ElementType val;
    for(int i=0; i<num; i++)
    {
        scanf("%s",&order);
        if(strcmp(order, push) == 0)
        {
            scanf("%d", &val);
            push_stack(S, val);
        }
        if(strcmp(order, pop) == 0)
        {
            if(!pop_stack(S, &val))
                printf("error\n");
            else
                printf("%d\n", val);
        }
        if(strcmp(order, top) == 0)
        {
            if(is_empty(S))
                printf("error\n");
            else
                printf("%d\n", get_top(S));
        }
    }
}

void main()
{
    Stack S = init_stack();
    operate(S);
}