/*
题目: 无法吃午餐的学生数量
描述：
学校的自助午餐提供圆形和方形的三明治，分别用数字 0 和 1 表示。所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。
餐厅里三明治的数量与学生的数量相同。所有三明治都放在一个栈里
每一轮：
1.如果队列最前面的学生 喜欢栈顶的三明治，那么会拿走它并离开队列。
否则，这名学生会放弃这个三明治并回到队列的尾部。
2.这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。

输入两个整数数组 students 和 sandwiches ，其中 sandwiches[i] 是栈里面第 i个三明治的类型（i = 0 是栈的顶部）
students[j] 是初始队列里第 j名学生对三明治的喜好（j = 0 是队列的最开始位置）。请你返回无法吃午餐的学生数量。

输入：
输入为两行，第一个行重数字表示学生对三明治的喜好（-1表示结束），第二个行中数字表示三明治的顺序（-1表示结束）
数组中元素数量均<100

输出：
输出为一个整数，表示无法吃午餐的学生的数量

输入输出样例：

输入
1 1 1 0 0 1 -1
1 0 0 0 1 1 -1
输出
3

解释：
最前面的学生拿走栈顶三明治离开，剩余学生队列为 [1,1,0,0,1]，三明治栈为 [0,0,0,1,1]；
最前面学生放弃栈顶三明治，排到队尾，剩余学生队列为 [1,0,0,1,1]，三明治栈为 [0,0,0,1,1]；
最前面学生放弃栈顶三明治，排到队尾，剩余学生队列为 [1,0,0,1,1]，三明治栈为 [0,0,0,1,1]；
最前面学生放弃栈顶三明治，排到队尾，剩余学生队列为 [0,0,1,1,1]，三明治栈为 [0,0,0,1,1]；
最前面的学生拿走栈顶三明治离开，剩余学生队列为 [0,1,1,1]，三明治栈为 [0,0,1,1]；
最前面的学生拿走栈顶三明治离开，剩余学生队列为 [1,1,1]，三明治栈为 [0,1,1]；
剩余三名学生无法吃到午饭
*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAXSIZE 200

typedef int ElementType;

typedef struct Queue
{
    int front;  //头指针
    int rear;   //尾指针
    int *pBase; //存储空间的基地址
} Queue;

typedef struct StackNode              
{
    ElementType data;
    struct StackNode *next;
} StackNode, *Stack;

void init_queue(Queue *Q)
{
    Q->pBase = (ElementType *)malloc(MAXSIZE*sizeof(Queue));
    Q->front = 0;
    Q->rear = 0;
}

bool is_full(Queue *Q)
{
    if((Q->rear + 1) % MAXSIZE == Q->front)
		return true;
	else
		return false;
}


bool is_empty(Queue *Q)
{
    if(Q->front == Q->rear)
		return true;
	else
		return false;
}

bool enter_queue(Queue *Q, ElementType val)
{
    if(is_full(Q))
        return false;
    else
    {
        Q->pBase[Q->rear] = val;    //ps[i] 里的中括号，C语言处理成运算符，ps[i] 等价于 *(ps+i)
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return true;
    }
}

bool out_queue(Queue *Q, ElementType *val)
{
    if(is_empty(Q))
		return false;
    else
    {
        *val = Q->pBase[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return true;
    }
}

ElementType get_head(Queue *Q)
{
	if(Q->front != Q->rear)
		return Q->pBase[Q->front];
}

int length_queue(Queue *Q)
{
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}

void function(Queue *student, Queue *lunch)
{
    int status = 1;
    while (!is_empty(student) && status ==1)
    {
        ElementType val;
        if(get_head(student) == get_head(lunch))
        {
            out_queue(student, &val);
            out_queue(lunch, &val);
        }
        else
        {
            out_queue(student, &val);
            enter_queue(student, val);
        }
        int i = student->front; 
        int cet = 0;
        while(i != student->rear)
        {
            if(student->pBase[i] != get_head(lunch))
            {
                cet++;
            }
            i = (i + 1) % MAXSIZE;
        }
        if(cet == length_queue(student))
            status = 0;
    }

    if(is_empty(student))
        printf("0");
    else
        printf("%d",length_queue(student));
    
}

void main()
{
    Queue student;
    Queue lunch;
    init_queue(&student);
    init_queue(&lunch);

    int n;
    scanf("%d", &n);
    while(n != -1)
    {
        enter_queue(&student, n);
        scanf("%d", &n);
    }
    scanf("%d", &n);
    while(n != -1)
    {
        enter_queue(&lunch, n);
        scanf("%d", &n);
    }

    function(&student, &lunch);
}

