#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> g[300005],ng[300005];
unordered_map<int,int> loc[300005];
#define lc g[u][loc[w][u]+1]
#define rc g[v][loc[w][v]-1]
int dfs(int u,int v,int w)
{
	int lsz=0,rsz=0;
	if(not(w==u-1 or w==n and u==1))lsz=dfs(u,w,lc);
	if(not(w==v+1 or w==1 and v==n))rsz=dfs(w,v,rc);
	if((lsz+rsz)%2)
		if(lsz%2==1)
			printf("%d %d\n%d %d\n",u,w,u,lc);
		else
			printf("%d %d\n%d %d\n",v,w,v,rc);
	else if(lsz%2==1)
		printf("%d %d\n%d %d\n",w,lc,w,rc);
	return lsz+rsz+1;
}
int main()
{
	scanf("%d",&n);
	if(n%2){puts("-1");return 0;}
	int u,v;
	for(int i=1;i<=n-3;i++)
	{
		scanf("%d%d",&u,&v);
		ng[u].push_back(v);
		ng[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		ng[i].push_back(i%n+1);
		ng[i%n+1].push_back(i);
	}
	for(int i=1;i<=n;i++)
		for(int j:ng[i])
		{
			if(j>i)continue;
			loc[i][j]=g[j].size();
			g[j].push_back(i);
		}
	for(int i=1;i<=n;i++)
		for(int j:ng[i])
		{
			if(j<i)continue;
			loc[i][j]=g[j].size();
			g[j].push_back(i);
		}
	printf("1 2\n");
	dfs(1,2,g[1][1]);
	return 0;
}