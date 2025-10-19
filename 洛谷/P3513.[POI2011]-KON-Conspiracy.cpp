#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 5010
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
constexpr const int mod = 998244353;
inline ll read() {
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
int n,deg[N],x;
int S,fac[N],inv[N];
inline int C(int n,int m) {
	return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
inline int Z(int x) {
	return (x>=mod?x-mod:x);
}
int main() {
	n=read();
	FOR(i,1,n) {
		deg[i]=read();
		int t=deg[i];
		while(t--) {
			x=read();
		}
		S+=deg[i];
	}
	S/=2;
	sort(deg+1,deg+n+1);
	reverse(deg+1,deg+n+1);
	fac[0]=1;
	FOR(i,1,n)fac[i]=1LL*fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	FOR(i,2,n)inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	FOR(i,2,n)inv[i]=1LL*inv[i-1]*inv[i]%mod;
	int sum=0,ans=0;
	FOR(i,1,n) {
		sum+=deg[i];
		if(sum==S+i*(i-1)/2) {
			int a=0,b=0,pos=i;
			while(pos>=1&&deg[pos]==deg[i])a++,b++,pos--;
			pos=i+1;
			while(pos<=n&&deg[pos]==deg[i])b++,pos++;
			ans=Z(ans+C(b,a));
		}
	}
	if(deg[n]==n-1)ans=Z(ans+mod-1);
	printf("%d\n", ans);
	return 0;
}
