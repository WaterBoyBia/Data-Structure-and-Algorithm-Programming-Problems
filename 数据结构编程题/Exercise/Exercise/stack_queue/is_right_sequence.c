/*
题目: 栈的压入、弹出序列
描述：
对输入的两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
1. 栈中数据的数量≤1000
2. push 的所有数字均不相同

输入：
输入为两行，每行包括一个数字序列，用空格隔开，-1结束。两个数字序列分别表示栈的压入顺序与弹出顺序

输出：
输出为true/false表示第二个序列能否为该栈的弹出顺序

输入输出样例：
输入
1 2 3 4 5 -1
4 5 3 2 1 -1
输出
true
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


void traverse_stack(StackNode *S)
{
    StackNode *p = S->next;
    while (p)
    {
        printf("%d ", p->data);
		p = p->next;
    }
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
    if(is_empty(S)) //这里的S不需要再取地址，因为传进来的本身已经是一个指针了
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
    if(is_empty(S)) 
	    return -1;
    else
    {
        StackNode *p = S->next;
        return p->data;
    }
}

bool is_sequence()
{
    int input[1000];
    int output[1000];
    int n;
    int i = 0;
    int t = 0;
    int len = 0;
    scanf("%d", &n);
    while(n != -1)
    {
        input[i] = n;
        scanf("%d", &n);
        i++;    
    }

    scanf("%d", &n);
    i = 0;
    while(n != -1)
    {
        output[i] = n;
        scanf("%d", &n);
        i++;    
        len++;
    }

    StackNode *S = init_stack();
    i = 0;
    for(int j=0; j<len; j++)
    {
        while(get_top(S) != output[j] && i<len)
        {
            n = input[i];
            push_stack(S, n);
            i++;
        }

        if(get_top(S) == output[j])
            pop_stack(S, &n);
        else
            return false;
    }
    return true;
}

void main()
{
    if(is_sequence())
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}