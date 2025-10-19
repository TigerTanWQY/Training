#include<bits/stdc++.h>
using namespace std;

constexpr const int N=2003;
vector<int>G[N],nG[N];
stack<int>stk;
bool ins[N];
int dfn[N],low[N],bel[N],sz[N],dep[N];
int idx,cnt;

void tarjan(int x,int pre) {
	low[x]=dfn[x]=++idx;
	ins[x]=1;
	stk.push(x);
	for(int i=0; i<G[x].size(); i++) {
		int to=G[x][i];
		if(to==pre)continue;
		if(!dfn[to]) {
			tarjan(to,x);
			low[x]=min(low[x],low[to]);
		} else if(ins[to])low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x]) {
		ins[x]=0;
		bel[x]=++cnt;
		sz[cnt]=1;
		while(x!=stk.top()) {
			ins[stk.top()]=0;
			bel[stk.top()]=cnt;
			++sz[cnt];
			stk.pop();
		}
		stk.pop();
	}
}
int id,tot,maxxx,sum;
void dfs(int x) {
	++sum;
	if(dep[x]>maxxx) {
		id=x;
		maxxx=dep[x];
	}
	for(int i=0; i<nG[x].size(); i++) {
		int to=nG[x][i];
		if(dep[to])continue;
		dep[to]=dep[x]+1;
		dfs(to);
		dep[to]=0;
	}
}
void dfs2(int x) {
	if(dep[x]>dep[id])id=x;
	int qaq=0;
	for(int i=0; i<nG[x].size(); i++) {
		int to=nG[x][i];
		if(dep[to])continue;
		++qaq;
		dep[to]=dep[x]+1;
		dfs2(to);
	}
	if(qaq==0)++tot;
}
int main() {
	ios::sync_with_stdio(0);
	int n,m,a,b,ans=0;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i])tarjan(i,0);
	for(int x=1; x<=n; x++)
		for(int i=0; i<G[x].size(); i++) {
			int to=G[x][i];
			if(bel[to]!=bel[x])nG[bel[x]].push_back(bel[to]);
		}
	for(int i=1; i<=cnt; i++)ans+=sz[i]-1;
	--ans;
	for(int i=1; i<=cnt; i++) {
		if(!dep[i]) {
			dep[i]=1;
			sum=0;
			maxxx=0;
			dfs(i);
			dep[i]=0;
			dep[id]=1;
			tot=1;
			maxxx=0;
			dfs2(id);
			if(tot!=1)ans+=sum-tot-dep[id]+2;
			++ans;
		}
	}
	cout<<ans;
}
