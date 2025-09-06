#include <iostream>
using namespace std;
using LL = long long;

LL tree[2000000];
LL n,m,prime[5000003],cnt,phi[20000003];
bool bj[20000003];

LL read() {
	LL x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void eular() {
	phi[1]=1;
	bj[1]=1;
	for(LL i=2; i<=20000000; i++) {
		if(!bj[i]) {
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for(LL j=1; j<=cnt&&prime[j]*i<=20000000; j++) {
			bj[prime[j]*i]=1;
			if(i%prime[j]==0) {
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}

LL lb(LL x)
{ return (x&(-x)); }

void updata(LL x,LL cost) {
	while(x<=n) {
		tree[x]+=cost;
		x+=lb(x);
	}
}

LL query(LL x) {
	LL ans=0;
	while(x>0) {
		ans+=tree[x];
		x-=lb(x);
	}
	return ans;
}

LL fastpow(LL di,LL zhi,LL p) {
	LL flag=0,yu=1;
	if(di>=p)flag=1,di%=p;
	while(zhi>0) {
		if(zhi%2==1)yu=yu*di;
		di=di*di;
		if(yu>=p)flag=1,yu%=p;
		if(di>=p)flag=1,di%=p;
		zhi=zhi/2;
	}
	if(flag)yu+=p;
	return yu;
}

LL Query(LL l,LL r,LL p) {
	LL now=query(l);
	if(l==r||p==1)return now>=p?now%p+p:now;
	return fastpow(now,Query(l+1,r,phi[p]),p);
}

int main() {
	eular();
	n=read();
	m=read();
	for(LL i=1; i<=n; i++) {
		LL x=read();
		updata(i,x);
		updata(i+1,-x);
	}
	for(LL i=1; i<=m; i++) {
		LL opt,x,y,z;
		opt=read(); x=read(); y=read(); z=read();
		if(opt==1) {
			updata(x,z);
			updata(y+1,-z);
		} else printf("%lld\n",Query(x,y,z)%z);
	}
	return 0;
}
