/*
题目: 两数相加
描述：
给你两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
输入：
链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0
-1表示链表结束符
输出：
输出链表

输入样例
7 2 4 3 -1
5 6 4 -1 

输出样例
7 8 0 7
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

void traverse_list(Lnode *L)
{
    Lnode *p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d ", p->data);
    }
}

bool is_Empty(Lnode *L)
{
    if(L->next == NULL)
        return true;
    else
        return false;
}

void head_insert(Lnode *L, ElementType val)
{
    Lnode *p = (Lnode *)malloc(sizeof(Lnode));
    p->data = val;
    p->next = L->next;  //先让P指向下一个元素，否则顺序反过来会访问不到
    L->next = p; 
}

LinkList sum(Lnode *L1, Lnode *L2)
{
    int extra = 0;
    int n;
    Lnode *p1 = L1;
    Lnode *p2 = L2;

    Lnode *output = init_list();

    while(p1->next != NULL && p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
        n = (p1->data + p2->data + extra)%10;
        head_insert(output, n);
        extra = (p1->data + p2->data + extra)/10;
    }

    if(p1->next == NULL)
    {
        while(p2->next != NULL)
        {
            p2 = p2->next;
            n = (p2->data + extra)%10;
            head_insert(output, n);
            extra = (p2->data + extra)/10;
        }
    }
    if(p2->next == NULL)
    {
        while(p1->next != NULL)
        {
            p1 = p1->next;
            n = (p1->data + extra)%10;
            head_insert(output, n);
            extra = (p1->data + extra)/10;
        }
    }

    if(extra != 0)
    {
        n = extra;
        head_insert(output, n);
    }

    return output;
}

void main()
{
    LinkList L1 = init_list();
    LinkList L2 = init_list();

    ElementType n;
    scanf("%d", &n);
    while(n != -1)
    {
        head_insert(L1, n);
        scanf("%d", &n);
    }
    scanf("%d", &n);
    while(n != -1)
    {
        head_insert(L2, n);
        scanf("%d", &n);
    }
    
    traverse_list(sum(L1, L2));
}