#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
struct BiTNode{
	ElemType data;
	BiTNode *lchild,*rchild;
};

int root[1000];
int a;
char b;
int i=1;
bool flag=true;
void read();

queue<BiTNode*> q;
BiTNode *rt;
void create();

int ti=1;
queue<BiTNode*> que;
void print(BiTNode *t);//层序遍历输出 1

queue<BiTNode*> que1;
int sign[100],top;
void print_ans(BiTNode *t);//层序遍历输出 2

int ki=1;
int root1[1000];
void MidOrderTraverse(BiTNode *t);//中序排序 

int main(){
	for(int o=0;o<100;o++){
		root[o]=110;
	}
	read();
	create();
	MidOrderTraverse(rt);
//	printf("\n");
//	for(int y=1;y<ki;y++){
//		printf("%d ",root1[y]);
//	}
//	printf("\n");
	int e,f,loc,loc2;
	int right=1;
	int r1=-1,r2=-1;
	for(int h=i;h>0;h--){
		if(root1[h]!=110&&r1==-1){
			r1=root1[h];
			loc=h;
		} 
		if(root1[h]!=110&&r2==-1){
			r2=root1[h];
			loc2=h;
		} 
		if(root1[h]!=110&&r1!=-1&&r2!=-1){
			r1=r2;
			r2=root1[h];
			loc=loc2;
		}
		if(r1<r2&&r1!=-1&&r2!=-1){
			e=r1;
			right=0;
//			printf("e:%d\n",e);
//			printf("loc:%d\n",loc);
			break;
		}

	}
	int tag=0;
	for(int m=loc;m>0;m--){
		if(root1[m]!=110&&root1[m]<e){
			loc2=m;
//			printf("loc2:%d\n",loc2);
			tag=1;
			break;
		}

	}
	if(tag==1){
		for(int u=loc2+1;u<loc;u++){
			if(root1[u]!=110){
				loc2=u;
				break;
			}
		}
	}
	if(tag==0){
		for(int n=1;n<loc;n++){
			if(root1[n]!=110){
				loc2=n;
				break;
			}
		}
	}
//	printf("loc2:%d\n",loc2);
	f=root1[loc2];
//	printf("f:%d\n",f);
	if(right==0){
		for(int h=1;h<i;h++){
			if(root[h]==e){
				root[h]=f;
			} else if(root[h]==f){
				root[h]=e;
			}	
		}
	}
	
	for(int h=1;h<i;h++){
		if(root[h]!=110){
			printf("%d",root[h]);
		} else {
			printf("null");
		}
		if(h!=i-1){
			printf(",");
		}
	}

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
			l->lchild=NULL;
			l->rchild=NULL;
			r=(BiTNode*)malloc(sizeof(BiTNode));
			r->data=110;
			r->lchild=NULL;
			r->rchild=NULL;
			//与父节点连接
			p->lchild=l;
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
			if(a->lchild){
				que.push(a->lchild);
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
		que1.push(x->lchild);
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
//int ki=1;
//int root1[1000]
void MidOrderTraverse(BiTNode* T){
	if(T){
		MidOrderTraverse(T->lchild);
		root1[ki]=T->data;				
		ki++;
//		printf("%d ",T->data);
		MidOrderTraverse(T->rchild);
	}
}
