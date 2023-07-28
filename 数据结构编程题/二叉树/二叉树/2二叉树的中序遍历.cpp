#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 1000
#define Elemtype int
Elemtype node[MAXSIZE], cnt = 0, len = 0;
typedef struct BiTNode
{
	Elemtype data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef struct Qnode
{
	BiTree data;
	struct Qnode *next;
}Qnode, *QueuePtr;
typedef struct LinkQueue
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

LinkQueue initQueue(LinkQueue q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(Qnode));
	q.front->next = NULL;
	return q;
}

void inQueue(LinkQueue *q, BiTree r){
	Qnode *p;
	p = (QueuePtr)malloc(sizeof(Qnode));
	p->data = r;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

BiTNode *getFront(LinkQueue q){
	return q.front->next->data;
}

void outQueue(LinkQueue *q)
{
	if(q->rear == q->front->next)
	{
		q->front->next = q->front->next->next;
		q->rear = q->front;
	}
	else q->front->next = q->front->next->next;
}

void midShowBiTree(BiTree r){
	if(r != NULL){
		midShowBiTree(r->lchild);
		printf("%d ", r->data);
		midShowBiTree(r->rchild);
	}
}



BiTNode *createBiTree(BiTNode *bt, int data[])
{
	LinkQueue q = initQueue(q);
	bt->data = data[cnt++];
	inQueue(&q, bt);
	BiTNode *s = bt;
	while(q.front != q.rear)
	{
		bt = getFront(q);
		outQueue(&q);
		if(data[cnt] == 255 || cnt >= len)
		{
			bt->lchild = NULL;
			cnt++;
		}
		else
		{
			bt->lchild = (BiTNode *)malloc(sizeof(BiTNode));
			bt->lchild->data = data[cnt];
			inQueue(&q, bt->lchild);
			cnt++;
		}
		if(data[cnt] == 255 || cnt >= len)
		{
			bt->rchild = NULL;
			cnt++;
		}
		else
		{
			bt->rchild = (BiTNode *)malloc(sizeof(BiTNode));
			bt->rchild->data = data[cnt];
			inQueue(&q, bt->rchild);
			cnt++;
		}
	}
	return s;
}

void midSaveBiTree(BiTNode *r){
	if(r != NULL){
		midSaveBiTree(r->lchild);
		node[cnt++] = r->data;
		midSaveBiTree(r->rchild);
	}
}

int main(int argc, char **argv)
{
	BiTNode *bt;
	bt = (BiTree)malloc(sizeof(BiTNode));
	Elemtype data[MAXSIZE] = {0}, e = 99, j, flag = 1;
	scanf("%d", &e);
	if(e == 99) data[len++] = 250;
	else 
	{
		data[len++] = e;
		j = getchar();
		while(j != '\n')
		{
			e = getchar();
			if(e == 110)
			{
				for(int i = 3; i > 0; i--) getchar();
				data[len++] = 255;
			}
			else data[len++] = e - 48;
			j = getchar();
		}
	}
	if(data[0] == 250) printf("true");
	else
	{
		bt = createBiTree(bt, data);
		cnt = 0;
		midSaveBiTree(bt);
		for(int i = 0; i < cnt/2; i++)
		{
			if(node[i] != node[cnt-i-1]) flag = 0;
		}
		if(flag == 1) printf("true");
		else printf("false");
	}
	return 0;
}