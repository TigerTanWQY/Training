#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N=120000;
int n,m,tu,wat[N],wo;
LL ans,T[N],num[N],q[N],d[N],s,last,x;

bool cmp(int A,int B)
{ return (q[A]<q[B] || (q[A]==q[B] && B>A)); }

void add(int x) { for(int i=x;i<=n+1;i+=(i&-i)) T[i]++; }

LL query(int x) { LL G=0; for(int i=x;i;i-=(i&-i)) G+=T[i]; return G; }

LL fnd(LL X,LL Y) {
	LL L=0,R=m-tu;
	while(L+1<R) {
		LL Mid=(L+R)>>1;
		if(Mid*Y<=X) L=Mid; else R=Mid;
	}
	if(R*Y<=X) L=R;
	return L;
}

int main() {
	scanf("%d%d%lld",&n,&m,&x); wo=0;
	for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
	for(int i=1;i<=n;i++) {
		LL B; scanf("%lld",&B);
		LL C=max(0ll,(x-d[i])/B+1);
		if(C>0) q[++wo]=C,wat[wo]=wo;
	}
	sort(wat+1,wat+1+wo,cmp);
	s=wo; last=0; tu=0; ans=0;
	for(int i=1;i<=wo;i++) {
		LL cnt=fnd(q[wat[i]]-last,s);
		if(cnt+tu==m) {
			ans+=(wo-i+1)*m;
			printf("%lld\n",ans);
			return 0;
		}
		if(q[wat[i]]-last-s*cnt-wat[i]+query(wat[i])>=0) {
			num[wat[i]]=cnt+tu+1;
			last++;
		} else num[wat[i]]=cnt+tu;
		last+=s*cnt; s--; tu+=cnt;
		add(wat[i]); ans+=num[wat[i]];
	}
	printf("%lld\n",ans);
	return 0;
}
