/*
题目: 二进制链表转整数
描述：
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是1。已知此链表是一个整数数字的二进制表示形式。请你返回该链表所表示数字的 十进制值
输入：
输入链表，链表不为空。链表的结点总数不超过 30。每个结点的值不是 0 就是 1。
-1表示链表结束符
输出：
输出十进制数

输入样例
1 0 1 -1
输出样例
5
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>

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

int bin_to_dec(Lnode *L)
{
    int cet = 0;
    int sum = 0;

    Lnode *p = L;
    while(p->next)
    {
        p = p->next;
        sum = sum + pow(2,cet)*(p->data);
        cet++;
    }

    return sum;
} 

void main()
{
    Lnode *L = init_list();

    ElementType n;
    scanf("%d", &n);
    while(n != -1)
    {
        head_insert(L, n);
        scanf("%d", &n);
    }

    printf("%d",bin_to_dec(L));
}