#include<bits/stdc++.h>
using namespace std;
constexpr const int N = 5e5 + 3;
int n,q,tot,head[N],dep[N],dfn[N],fa[N][20],cnt,ST[2][N][20],SST[2][N][20],len[20],t[N];
struct node
{ int from,to,next; }
k[N];
void add(int from,int to) {
	k[++tot].to=to;
	k[tot].from=from;
	k[tot].next=head[from];
	head[from]=tot;
}
void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	dfn[u]=++cnt;
	t[cnt]=u;
	for(int i=1;i<=19;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=k[i].next)dfs(k[i].to,u);
}
int lca(int k,int b) {
	k=t[k],b=t[b];
	if(dep[k]<dep[b])swap(k,b);
	for(int i=19;i>=0;i--)if(dep[fa[k][i]]>=dep[b])k=fa[k][i];
	if(k==b)return dep[k];
	for(int i=19;i>=0;i--)if(fa[k][i]!=fa[b][i])k=fa[k][i],b=fa[b][i];
	return dep[fa[k][0]];
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	len[0]=1;
	for(int i=1;i<=19;i++)len[i]=2*len[i-1];
	for(int i=2,x;i<=n;i++) {
		cin >> x;
		add(x,i);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) {
		ST[0][i][0]=dfn[i];
		ST[1][i][0]=dfn[i];
		SST[0][i][0]=0;
		SST[1][i][0]=10000000;
	}
	for(int j=1;j<=19;j++)
		for(int i=1;i+len[j]-1<=n;i++) {
			ST[0][i][j]=max(ST[0][i][j-1],ST[0][i+len[j-1]][j-1]);
			ST[1][i][j]=min(ST[1][i][j-1],ST[1][i+len[j-1]][j-1]);
			SST[0][i][j]=max(min(ST[0][i][j-1],ST[0][i+len[j-1]][j-1]),max(SST[0][i][j-1],SST[0][i+len[j-1]][j-1]));
			SST[1][i][j]=min(max(ST[1][i][j-1],ST[1][i+len[j-1]][j-1]),min(SST[1][i][j-1],SST[1][i+len[j-1]][j-1]));
		}
	while(q--) {
		int l,r;
		cin >> l >> r;
		int k=log2(r-l+1);
		int maxn=max(ST[0][l][k],ST[0][r-len[k]+1][k]),minn=min(ST[1][l][k],ST[1][r-len[k]+1][k]);
		int maxs=max(SST[0][l][k],SST[0][r-len[k]+1][k]),mins=min(SST[1][l][k],SST[1][r-len[k]+1][k]);
		if(ST[0][r-len[k]+1][k]!=ST[0][l][k])maxs=max(maxs,min(ST[0][l][k],ST[0][r-len[k]+1][k]));
		if(ST[1][l][k]!=ST[1][r-len[k]+1][k])mins=min(mins,max(ST[1][l][k],ST[1][r-len[k]+1][k]));
		int ans1=lca(maxn,mins),ans2=lca(maxs,minn);
		if(ans1>ans2)cout<<t[minn]<<" "<<ans1-1<<"\n";
		else cout<<t[maxn]<<" "<<ans2-1<<"\n";
	}
	cout.flush(); return 0;
}
