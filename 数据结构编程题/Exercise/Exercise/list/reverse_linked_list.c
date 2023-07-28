/*
题目: 从尾到头打印链表
描述：
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

输入：
输入链表，0 <= 链表长度 <= 10000
-1表示链表结束符
输出
输出反转后的链表

输入样例
1 2 6 3 4 5 6 -1 
输出样例
6 5 4 3 6 2 1
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef int ElementType;

typedef struct Lnode{
    ElementType data;   //存储的数据
    struct Lnode *next; //指向节点的指针类型
} Lnode, *LinkList;

LinkList init_list()
{
    Lnode *L;
    L= (Lnode *)malloc(sizeof(Lnode));   //不存放数据的头节点;  
    L->next = NULL; 
    return L;
}

void head_insert(Lnode *L, ElementType val)
{
    Lnode *p = (Lnode *)malloc(sizeof(Lnode));
    p->data = val;
    p->next = L->next;  //先让P指向下一个元素，否则顺序反过来会访问不到
    L->next = p; 
}

void traverse_list(Lnode *L)
{
    Lnode *p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d ", p->data);
    }
}

void reverse()
{
    Lnode *L = init_list();

    ElementType n;
    scanf("%d", &n);
    while(n != -1)
    {
        head_insert(L, n);
        scanf("%d", &n);
    }

    traverse_list(L);
}

void main()
{
    reverse();
}