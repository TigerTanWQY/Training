#include <bits/stdc++.h>
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

const int MAXN=10003,MAXM=103,MAXV=2e6+3;
int n,m,q,tot,cols,col[MAXV],dfn[MAXV],low[MAXV],in[MAXV];
vector<int> G[MAXV];
int gid(int x,int y,int op) {return (x-1)*(m+2)+y+op*n*(m+2);}
stack<int> st;

void tarjan(int u) {
	dfn[u]=low[u]=++tot,st.push(u),in[u]=1;
	for(auto v:G[u]) {
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(in[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]) {
		++cols;
		while(1) {
			int v=st.top(); st.pop();
			in[v]=0,col[v]=cols;
			if(v==u) break ;
		}
	}
	return ;
}

void add(int u,int v) {return G[u].push_back(v),void();}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	ffor(i,1,n) ffor(j,0,m) add(gid(i,j,0),gid(i,j+1,0)),add(gid(i,j+1,1),gid(i,j,1));
	ffor(i,1,q) {
		int a,b,l,r;
		cin>>a>>b>>l>>r;
		ffor(j,0,m+1) add(gid(a,j,0),gid(b,min(m+1,max(0,l-j+1)),1));
		ffor(j,0,m+1) add(gid(a,j,1),gid(b,max(0,min(m+1,r-j+1)),0));
		swap(a,b);
		ffor(j,0,m+1) add(gid(a,j,0),gid(b,min(m+1,max(0,l-j+1)),1));
		ffor(j,0,m+1) add(gid(a,j,1),gid(b,max(0,min(m+1,r-j+1)),0));
	}
	ffor(i,1,n) add(gid(i,0,0),gid(i,0,1)),add(gid(i,m+1,1),gid(i,m+1,0));
	ffor(i,0,n*(m+2)*2-1) if(!dfn[i]) tarjan(i);
	ffor(i,1,n) ffor(j,0,m+1) if(col[gid(i,j,0)]==col[gid(i,j,1)]) return cout<<"-1",0;
	ffor(i,1,n) ffor(j,0,m+1) if(col[gid(i,j,0)]<col[gid(i,j,1)]) {cout<<j-1<<' ';break ;}
	return 0;
}
