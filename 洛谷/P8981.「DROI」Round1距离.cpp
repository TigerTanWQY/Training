#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N=5e6+10,mod=998244353;
int n,k,len,ans,s[N],l[N];
int h[N],e[N<<1],ne[N<<1],idx;
struct node
{
	int val,cnt;
}p[N],fi[N],se[N];
 int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
 void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
 void dfs(int u,int fa)
{
	fi[u].val=fi[u].cnt=1;
	for(int i=h[u];~i;i=ne[i])
	{
		if(e[i]==fa)	continue;
		dfs(e[i],u);
		if(fi[u].val+fi[e[i]].val>p[u].val) p[u]={fi[u].val+fi[e[i]].val,(int)((LL)fi[u].cnt*fi[e[i]].cnt%mod)};
		else if(fi[u].val+fi[e[i]].val==p[u].val) p[u].cnt=(p[u].cnt+(LL)fi[u].cnt*fi[e[i]].cnt%mod)%mod;
		if(fi[e[i]].val+1>fi[u].val) se[u]=fi[u],fi[u]={fi[e[i]].val+1,fi[e[i]].cnt};
		else if(fi[e[i]].val+1==fi[u].val) fi[u].cnt+=fi[e[i]].cnt;
		else if(fi[e[i]].val+1>se[u].val) se[u]={fi[e[i]].val+1,fi[e[i]].cnt};
		else if(fi[e[i]].val+1==se[u].val) se[u].cnt+=fi[e[i]].cnt;
	}
	len=max(len,p[u].val);
}
 void DFS(int u,int fa,int up,int num)
{
	s[u]=p[u].cnt=(p[u].val==len?p[u].cnt:0);
	for(int i=h[u];~i;i=ne[i])
	{
		if(e[i]==fa)	continue;
		int cur=max(up+1,(fi[e[i]].val+1==fi[u].val&&fi[e[i]].cnt==fi[u].cnt)?se[u].val:fi[u].val);
		if(fi[e[i]].val+1==fi[u].val&&fi[e[i]].cnt==fi[u].cnt) DFS(e[i],u,cur,num*((up+1)==cur)+se[u].cnt*((se[u].val)==cur));
		else if(fi[e[i]].val+1==fi[u].val) DFS(e[i],u,cur,num*((up+1)==cur)+(fi[u].cnt-fi[e[i]].cnt)*((fi[u].val)==cur));
		else DFS(e[i],u,cur,num*((up+1)==cur)+fi[u].cnt*((fi[u].val)==cur));
		l[u]=(l[u]+l[e[i]])%mod;s[u]=(s[u]+s[e[i]])%mod;
	}
	if(up+1==len) l[u]=(l[u]+num)%mod;
	if(fi[u].val==len) l[u]=(l[u]+fi[u].cnt)%mod;
}
 int pwr(int x,int y){return y==1?x:(LL)x*x%mod;}
int main()
{
	memset(h,-1,sizeof h);
	n=read(),k=read();
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs(1,-1);DFS(1,-1,0,0);
	for(int i=1;i<=n;i++) ans=(ans+pwr(p[i].cnt+(l[i]-s[i]*2),k))%mod;
	printf("%d",ans);
	return 0;
}
