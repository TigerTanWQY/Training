#include<bits/stdc++.h>
#define M 100005
using namespace std;
using V = vector<int>;
int n,m,q,fa[M][20],dep[M],top[M],sz[M],son[M];
V G[M],cty[M],num[M][20],ans;
V up(vector<int>&b,vector<int>&c){
	int i=0,j=0;
	V a;
	a.clear();
	while(i<b.size()&&j<c.size()&&a.size()<10){
		if(b[i]<c[j])a.push_back(b[i++]);
		else a.push_back(c[j++]);
	}
	while(i<b.size()&&a.size()<10)a.push_back(b[i++]);
	while(j<c.size()&&a.size()<10)a.push_back(c[j++]);
	return a;
}
void dfs(int x,int f,int d){
	dep[x]=d;
	fa[x][0]=f;fa[x][1]=fa[f][0];
	num[x][0]=cty[x];num[x][1]=up(cty[x],cty[f]);
	for(int i=0;i<G[x].size();i++){
		int u=G[x][i];
		if(u==f)continue;
		dfs(u,x,d+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1,a;i<=m;i++){
		scanf("%d",&a);
		cty[a].push_back(i);
	}
	dfs(1,0,1);
	for(int j=2;j<=19;j++)
		for(int i=1;i<=n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
			num[i][j]=up(num[i][j-1],num[fa[i][j-1]][j-1]);
		}
	for(int i=1,u,v,a;i<=q;i++){
		scanf("%d%d%d",&u,&v,&a);
		ans.clear();
		if(dep[u]>dep[v])swap(u,v);
		int step=dep[v]-dep[u];
		for(int i=19;i>=0;i--)
			if(step&1<<i)ans=up(ans,num[v][i]),v=fa[v][i];
		if(u==v){
			ans=up(ans,num[v][0]);
			goto e;
		}
		for(int i=19;i>=0;i--){
			if(fa[u][i]!=fa[v][i]){
				ans=up(num[u][i],ans);
				ans=up(num[v][i],ans);
				u=fa[u][i];
				v=fa[v][i];
			}
		}
		ans=up(ans,num[u][0]);
		if(u!=v)ans=up(ans,num[v][1]);
		e:;
		int len=ans.size();
		len=min(len,a);
		printf("%d",len);
		for(int i=0;i<len;i++)
			printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
