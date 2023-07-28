/*
题目：回文链表
描述：
“回文”指正读反读均相同的字符序列，如“abcdcba”和“abba”均是回文，使用栈这种数据结构判断给定字符序列是否为回文，要求使用链栈实现。

输入：
一个字符序列，字符序列长度≤1000

输出：
输出为true/false，分别表示输入的字符序列是否为回文

输入输出样例：
输入 abcda
输出 false
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char ElementType;

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

bool is_palindrome()
{
    char *p = NULL;
    p = (char *)malloc(sizeof(char));
    scanf("%s", p);

    StackNode *S = init_stack();

    int len = strlen(p);
    char str[len];

    for (int i = 0; i < len; i++)
    {
        push_stack(S, *p);
        str[i] = *p;
        p++;
    }

    char temp_str[len];
    StackNode *sp = S->next;
    int cnt = len;

    while (sp && sp->next)
    {
        temp_str[len-cnt] = sp->data;
        cnt--;
		sp = sp->next;
    }
    temp_str[len-cnt] = sp->data;

    /*
    直接用strcmp()函数比较是错误的，因为temp_str并没有初始化，也就是末尾没有'/0'，编译器在字符末尾会加入一些奇奇怪怪
    的符号，所以定义时长度加一，在最后加上'\0'
    temp_str[len-cnt+1] = '\0';
    */
    for(int j=0; j<len; j++)    
    {
        if(temp_str[j] != str[j])
            return false;
    }
    return true;
}

void main()
{
    if(is_palindrome())
        printf("true");
    else
        printf("false");
}


