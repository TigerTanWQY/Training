#include <bits/stdc++.h>
using namespace std;

int n,s,t,dis[600005],pre[600005];
int cnt,prime[300005],f[300005];
struct graph {
	int tot,hd[600005];
	int nxt[10000005],to[10000005];
	void add(int u,int v) {
		nxt[++tot]=hd[u];
		hd[u]=tot;
		to[tot]=v;
		return ;
	}
}g;
queue<int> q;
stack<int> ans;

int main() {
	for (int i=2;i<=300000;i++)
		if (!f[i]) {
			prime[++cnt]=i;
			for (int j=2*i;j<=300000;j+=i) f[j]=1;
		}
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int x;
		scanf("%d",&x);
		for (int j=1;j<=cnt&&prime[j]*prime[j]<=x;j++)
			if (x%prime[j]==0) {
				g.add(i,n+j);
				g.add(n+j,i);
				while (x%prime[j]==0) x/=prime[j];
			}
		if (x!=1) {
			int pos=lower_bound(prime+1,prime+cnt+1,x)-prime;
			g.add(i,n+pos);
			g.add(n+pos,i);
		}
	}
	scanf("%d%d",&s,&t);
	memset(dis,-1,sizeof(dis));
	q.push(s);
	dis[s]=0;
	while (!q.empty()) {
		int now=q.front();q.pop();
		for (int i=g.hd[now];i;i=g.nxt[i])
			if (dis[g.to[i]]==-1) {
				dis[g.to[i]]=dis[now]+1;
				pre[g.to[i]]=now;
				q.push(g.to[i]);
			}
	}
	if (dis[t]==-1) {puts("-1");return 0;}
	for (int now=t;now;now=pre[now])
		if (now<=n) ans.push(now);
	printf("%d\n",(int)ans.size());
	while (!ans.empty()) printf("%d ",ans.top()),ans.pop();
	puts("");
	return 0;
}
