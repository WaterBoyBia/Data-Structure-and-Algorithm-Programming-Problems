#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
struct BiTNode{
	ElemType data,dep;
	BiTNode *lchind,*rchild,*fa;
};

int root[1000];
int a;
char b;
int i=1;
bool flag=true;
void read();

queue<BiTNode*> q;
BiTNode *rt;
int deep=1;
void create();

int ti=1;
queue<BiTNode*> que;
void print(BiTNode *t);//层序遍历输出 1

queue<BiTNode*> que1;
int sign[100],top;
void print_ans(BiTNode *t);//层序遍历输出 2

int m,n;
BiTNode *t1,*t2;
void getDep(BiTNode *t,int dep);

int main(){
	for(int o=0;o<100;o++){
		root[o]=110;
	}
	read();
	create();
	scanf("%d",&m);
	scanf("%d",&n);
	getDep(rt,1);
	while(t1->data!=t2->data){
		if(t1->dep>t2->dep){
			t1=t1->fa;
		} else {
			t2=t2->fa;
		}
	}
	printf("%d",t1->data);
	return 0;
}

void read(){
	while(b!='\n'){
		scanf("%d",&a);
		b=getchar();
		if(b!=110){//输入null时,scanf("%d")读取不了n，所以n被getchar读取 
			root[i]=a;
			i++;
		} else {
			b=getchar();//读取u 
			b=getchar();//读取l
			b=getchar();//读取l
			b=getchar();//读取,
			root[i]=110;//(int)'n'=110
			i++;
		}
		if(b=='\n'){
			break;
		}
	}
}

void create(){
	BiTNode *p,*l,*r;
	rt = new BiTNode();
	int ct=1;
	q.push(rt);
	while(ct<i){
		p=q.front();
		//用完出栈 
		q.pop();
		//if(root[ct]!=110){
		p->data = root[ct];
		ct++;
		//}
		if(p->data!=110){
			//对左右子树初始化
			l=(BiTNode*) malloc(sizeof(BiTNode));
			l->data=110;
			l->lchind=NULL;
			l->rchild=NULL;
			l->fa=p;
			r=(BiTNode*)malloc(sizeof(BiTNode));
			r->data=110;
			r->lchind=NULL;
			r->rchild=NULL;
			r->fa=p;
			//与父节点连接
			p->lchind=l;
			p->rchild=r;
			//入栈
			q.push(l);
			q.push(r);
		}
		
	}
}

void print(BiTNode *t){
	if(t){
		BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
		BiTNode* a = (BiTNode*)malloc(sizeof(BiTNode));
		p=t;
		que.push(p);
		while(ti<i){
			a=que.front();
			que.pop();
			if(a->data!=110&&ti<i){
				printf("%d",a->data);
				ti++;
			} else if(a->data==110&&ti<i) {
				printf("null");
				ti++;
			}
			if(ti<i){
				printf(",");
			}
			if(a->lchind){
				que.push(a->lchind);
			}
			if(a->rchild){
				que.push(a->rchild);
			}
			
		}
	}
}

void print_ans(BiTNode *t){
	que1.push(rt);
	while(!que1.empty()){
		BiTNode* x=que1.front();
		que1.pop();
		sign[++top]=x->data;
		if(x->data==110) continue;
		que1.push(x->lchind);
		que1.push(x->rchild);
	}
	while(sign[top]==110) --top;
	printf("%d",sign[1]);
	for(int i=2;i<=top;++i){
		putchar(',');
		if(sign[i]==110) printf("null");
		else printf("%d",sign[i]);
	}
}

//int m,n;
//BiTNode *t1,*t2;
void getDep(BiTNode *t,int dep){
	if(t->data==m) t1=t;
	if(t->data==n) t2=t;
	if(t->data==110) return;
	t->dep=dep;
	getDep(t->lchind,dep+1);
	getDep(t->rchild,dep+1);
}

