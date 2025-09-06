#include<bits/stdc++.h>
using namespace std;
int read(){
	 char c=getchar(); int f=1,x=0;
	while(!isdigit(c)) { if(c=='-') f=-1;c=getchar(); }
	while(isdigit(c)) { x=x*10+c-'0';c=getchar(); }
	return x*f;
}
int n,m,p,q,fa[1000001],col[1000001];
inline int myfind(int x){ if(x==fa[x]) return x;return fa[x]=myfind(fa[x]); }
int main(){
	n=read(),m=read(),p=read(),q=read();
	for( int i=1;i<=n;++i) fa[i]=i;
	for( int i=m;i>=1;--i){
		int l=(i*p+q)%n+1,r=(i*q+p)%n+1;
		if(l>r) swap(l,r);
		for( int j=r;j>=l;){
			int t=myfind(j);
			if(t==j){
				col[j]=i,fa[j]=myfind(j-1);
			}j=fa[j];
		}
	}
	for( int i=1;i<=n;++i) printf("%d\n",col[i]);
	return 0;
}
