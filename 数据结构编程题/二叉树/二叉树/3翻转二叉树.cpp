#include <bits/stdc++.h>
using namespace std;
#define fl putchar('\n')
#define bl putchar(' ')
bool over;
const int maxn=1e5+5;
int a[maxn],n;
void read(int &x){
	x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='\n'){
			over=1;
			--n;
			return;
		}
		if(c=='n'){
			x=-1;
			return;
		}
	}
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+c-48;
	if(c=='\n') over=1;
}
struct tree{
	int val;
	tree *lchild,*rson;
};
tree *rt;
void init(){
	while(!over){
		read(a[++n]);
	}
}
int ct;
queue<tree*> q;
void build(){
	rt=new tree();
	q.push(rt);
	while(!q.empty()){
		tree* x=q.front();q.pop();
		++ct; if(ct>n) a[ct]=-1;
		x->val=a[ct];
		if(a[ct]==-1) continue;
		x->lchild=new tree();
		x->rson=new tree();
		q.push(x->lchild);
		q.push(x->rson);
	}
}
void rev(tree *x){
	if(x->val==-1) return;
	rev(x->lchild);
	rev(x->rson);
	swap(x->lchild,x->rson);
}
int stk[maxn],top;
void print_ans(){
	q.push(rt);
	while(!q.empty()){
		tree* x=q.front();q.pop();
		stk[++top]=x->val;
		if(x->val==-1) continue;
		q.push(x->lchild);
		q.push(x->rson);
	}
	while(stk[top]==-1) --top;
	cout<<stk[1];
	for(int i=2;i<=top;++i){
		putchar(',');
		if(stk[i]==-1) printf("null");
		else cout<<stk[i];
	}
}
int main(){
	init();
	build();
	rev(rt);
	print_ans();
	return 0;
}
