#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

constexpr const int N = 3e5 + 3, rp = 1e6 + 3;
vector<pair<int, int>> G[N];
int n, m, cnt, ans, maxt,q[N],p[N],b[N],d[N],dp[N],fa[N][20];
struct node{int u,v,w,t;}a[N];

inline void dfs(int x,int f) {
	p[++cnt]=x;
	d[x]=d[f]+1; dp[x]=dp[f]+b[x]; fa[x][0]=f;
	for(int i=1;i<20;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto a:G[x]) if(a.fi!=f) b[a.fi]=a.se,dfs(a.fi,x);
}

inline int get(int u,int v) {
	if(d[u]<d[v]) swap(u,v);
	int x=d[u]-d[v];
	for(int i=0;(1<<i)<=x;++i) if((1<<i)&x) u=fa[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;--i)
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

inline int cr(int x) {
	cnt=0; memset(q,0,sizeof q);
	for(int i=1;i<=m;++i)
		if(a[i].t>x) {
			++cnt;
			++q[a[i].u]; ++q[a[i].v];
			q[a[i].w]-=2;
		}
	for(int i=n;i>=1;--i) q[fa[p[i]][0]]+=q[p[i]];
	for(int i=1;i<=n;++i)
		if(q[i]==cnt&&maxt-b[i]<=x)
			return 1;
	return 0;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	int u,v,w;
	for(int i=1;i<n;++i) {
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	dfs(1,0);
	for(int i=1;i<=m;++i) {
		cin >> u >> v;
		a[i].u = u; a[i].v = v;
		a[i].w=w=get(u,v);
		a[i].t=dp[u]+dp[v]-2*dp[w];
		maxt=max(maxt,a[i].t);
	}
	int L=0,R=maxt; ans=maxt;
	while(L<=R) {
		int mi=(L+R)>>1;
		if(cr(mi)) R=mi-1,ans=mi;
		else L=mi+1;
	}
	cout << ans << endl;
	return 0;
}
