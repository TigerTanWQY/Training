#include <bits/stdc++.h>
using namespace std;

constexpr const int N=1e5+9,SZ=2.2e6;
char buf[SZ],*pp=buf-1;
int k,a[N],b[N],c[N],p[N],q[N],v[N],cnt[N],ans[N],*e;

inline int in(){
	while(*++pp<'-');
	int x=*pp&15;
	while(*++pp>'-')x=x*10+(*pp&15);
	return x;
}
void out(int x){
	if(x>9)out(x/10);
	*++pp=x%10|'0';
}
inline bool cmp(int x,int y){
	return a[x]<a[y]||(a[x]==a[y]&&(b[x]<b[y]||(b[x]==b[y]&&c[x]<c[y])));
}
inline void upd(int i,int v){
	for(;i<=k;i+=i&-i)e[i]+=v;
}
inline int ask(int i){
	int v=0;
	for(;i;i-=i&-i)v+=e[i];
	return v;
}
void cdq(int*p,int n){
	if(n==1)return;
	int m=n>>1,i,j,k;
	cdq(p,m);cdq(p+m,n-m);
	memcpy(q,p,n<<2);
	for(k=i=0,j=m;i<m&&j<n;++k){
		int x=q[i],y=q[j];
		if(b[x]<=b[y])upd(c[p[k]=x],v[x]),++i;
		else  cnt[y]+=ask(c[p[k]=y])     ,++j;
	}
	for(;j<n;++j)cnt[q[j]]+=ask(c[q[j]]);
	memcpy(p+k,q+i,(m-i)<<2);
	for(--i;~i;--i)upd(c[q[i]],-v[q[i]]);
}
int main(){
	fread(buf,1,SZ,stdin);
	int n=in(),i,j;k=in();e=new int[k+9];
	for(i=0;i<n;++i)
		p[i]=i,a[i]=in(),b[i]=in(),c[i]=in();
	sort(p,p+n,cmp);
	for(i=1,j=0;i<n;++i){
		int x=p[i],y=p[j];++v[y];
		if(a[x]^a[y]||b[x]^b[y]||c[x]^c[y])p[++j]=x;
	}
	++v[p[j++]];
	cdq(p,j);
	for(i=0;i<j;++i)
		ans[cnt[p[i]]+v[p[i]]-1]+=v[p[i]];
	for(pp=buf-1,i=0;i<n;++i)
		out(ans[i]),*++pp='\n';
	fwrite(buf,1,pp-buf+1,stdout);
	return 0;
}
