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

	tree *lson,*rson;

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

		x->lson=new tree();

		x->rson=new tree();

		q.push(x->lson);

		q.push(x->rson);

	}

}

vector<int> v[maxn];

void getv(tree* x,int dep){

	if(x->val==-1) return;

	v[dep].push_back(x->val);

	getv(x->lson,dep+1);

	getv(x->rson,dep+1);

}

int main(){

	init();

	build();

	getv(rt,0);

	int cur=0;

	while(v[cur].size()){

		if(cur&1){

			int minn=v[cur][0];

			if(minn&1){

				cout<<"false";

				return 0;

			}

			for(int i=1;i<v[cur].size();++i){

				if(v[cur][i]>=minn||(v[cur][i]&1)){

					cout<<"false";

					return 0;

				}

				minn=v[cur][i];

			}

		}

		else{

			int maxx=v[cur][0];

			if(!(maxx&1)){

				cout<<"false";

				return 0;

			}

			for(int i=1;i<v[cur].size();++i){

				if(v[cur][i]<=maxx||(!(v[cur][i]&1))){

					cout<<"false";

					return 0;

				}

				maxx=v[cur][i];

			}

		}

		++cur;

	}

	cout<<"true";

	return 0;

}
