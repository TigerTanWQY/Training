#include <bits/stdc++.h>
using namespace std;
constexpr const int N=1e5+3;
void read(int &x){
	x=0;int f=1;char w=getchar();
	while(w<'0'||w>'9'){if(w=='-')f=-1;w=getchar();}
	while(w<='9'&&w>='0'){x=x*10+w-'0';w=getchar();}
	x*=f;
}
int m,n,f[N],ans[N];
int fnd(int x){return f[x]==x?x:f[x]=fnd(f[x]);}
struct node{int id,a,b,v;}a[N];
inline bool cmp(node s1,node s2){return s1.v<s2.v;}
struct edge{int t,v,nxt;}e[N<<1];
int head[N],esum,t[N],nt;
inline void add(int fr,int to,int val){
	if(t[fr]^nt)t[fr]=nt,head[fr]=0;
	e[++esum]={to,val,head[fr]};head[fr]=esum;
}
int dfn[N],cnt,low[N],about[N],vis[N],st[N<<1],top;
void dfs(int u,int come){
	dfn[u]=low[u]=++cnt;vis[u]=nt;
	if(t[u]^nt)return;
	for(int i=head[u],th;i;i=e[i].nxt){
		if((i^come)==1)continue;
		if(about[th=e[i].t]^nt)continue;
		if(dfn[th]&&vis[th]==nt)low[u]=min(low[u],dfn[th]);
		else{
			dfs(th,i);low[u]=min(low[u],low[th]);
			if(low[th]>dfn[u])ans[e[i].v]=1;
		}
	}
}
char out[3][20]={"none","at least one","any"};
int main(){
	read(m);read(n);
	for(int i=1;i<=n;i++){read(a[i].a);read(a[i].b);read(a[i].v);a[i].id=i;}
	sort(a+1,a+n+1,cmp);for(int i=1;i<=m;i++)f[i]=i;
	for(int i=1;i<=n;){
		top=cnt=0;esum=1;nt++;int j=i;for(;a[j+1].v==a[i].v;++j);
		for(int k=i;k<=j;k++)
			if(fnd(a[k].a)^fnd(a[k].b)){
				int fa=fnd(a[k].a),fb=fnd(a[k].b);
				add(fa,fb,a[k].id);add(fb,fa,a[k].id);
				about[fa]=about[fb]=nt;
				st[++top]=fa;st[++top]=fb;
			} else ans[a[k].id]=-1;
		for(int k=1;k<=top;k++)if(vis[st[k]]^nt)dfs(st[k],0);
		for(;i<=j;i++)f[fnd(a[i].a)]=fnd(a[i].b);
	}
	for(int i=1;i<=n;i++)puts(out[ans[i]+1]);
	return 0;
}
