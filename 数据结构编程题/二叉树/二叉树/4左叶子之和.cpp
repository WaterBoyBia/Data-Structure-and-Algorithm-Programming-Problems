#include <stdio.h>
#include <stdlib.h>
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
void midShowBiTree(BiTree r){
	if(r != NULL){
		midShowBiTree(r->lchild);
		printf("%d ", r->data);
		midShowBiTree(r->rchild);
	}
}
int left_leaves_sum(BiTNode *r)
{
	if(r == NULL) return 0;
	BiTNode *rleft = r->lchild;
	if(rleft && !rleft->lchild && !rleft->rchild)
	{
		cnt += rleft->data;
		left_leaves_sum(r->rchild);
	}
	else
	{
		left_leaves_sum(r->lchild);
		left_leaves_sum(r->rchild);
	}
	return cnt;
}
int main(int argc, char **argv)
{
	BiTNode *bt;
	bt = (BiTree)malloc(sizeof(BiTNode));
	Elemtype data[MAXSIZE] = {0}, e = 99, j;
	scanf("%d", &e);
	if(e == 99) data[len++] = 250;
	else 
	{
		data[len++] = e;
		j = getchar();
		while(j != '\n')
		{
			e = 99;
			scanf("%d", &e);
			if(e == 99)
			{
				for(int i = 4; i > 0; i--) getchar();
				data[len++] = 255;
			}
			else data[len++] = e;
			j = getchar();
		}
	}
	if(len == 1 && data[0] == 250) printf("0");
	else
	{
		bt = createBiTree(bt, data);
		cnt = 0;
		printf("%d", left_leaves_sum(bt));
	}
	return 0;
}
