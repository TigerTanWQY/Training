#include <bits/stdc++.h>
using namespace std;

constexpr const int N=3e6+3;
long long n,m,Q,fa[N],now=1,son[N],ans[N];

struct node
{ int u,v,time,id; }
edge[N],q[N];

bool cmp(node a,node b)
{ return a.time>b.time; }

int fnd(int x) {
	if(x!=fa[x])return fa[x]=fnd(fa[x]);
	else return x;
}

void mrge(int a,int b) {
	int A=fnd(a),B=fnd(b);
	if(A>B)swap(A,B);
	if(A!=B)son[B]+=son[A],son[A]=0;
	fa[A]=B;
}

int qry(int x) {
	if(x!=fa[x])return qry(fa[x]);
	else return son[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].time;
	for(int i=1;i<=n;i++)fa[i]=i,son[i]=1;
	sort(edge+1,edge+1+m,cmp);
	cin>>Q;
	for(int i=1;i<=Q;i++)cin>>q[i].u>>q[i].time,q[i].id=i;
	sort(q+1,q+1+Q,cmp);
	for(int i=1;i<=Q;i++) {
        while(q[i].time<edge[now].time) {
			mrge(edge[now].u,edge[now].v);
			now++;
		}
		ans[q[i].id]=qry(q[i].u);
	}
	for(int i=1;i<=Q;i++)cout<<ans[i]<<endl;
	return 0;
}
