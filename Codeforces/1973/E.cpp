#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int g;
int n,a[N];
ll res;
int pos;
int maxx,minn;
int main() {
	scanf("%d",&g);
	while(g--) {
		res=0;
		scanf("%d",&n);
		pos=-1;
		maxx=0;minn=1e9;
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if(i==a[i]) continue;
			if(pos==-1) pos=a[i]+i;
			else if(pos^(a[i]+i)) pos=-2;
			maxx=max(maxx,a[i]);
			minn=min(minn,a[i]);
		}
		if(minn==1e9) {
			printf("%lld\n",1ll*n*(n*2+1));
			continue;
		}
		if(pos>0) res=1;
		res+=1ll*(maxx+n-1)*(n-maxx)/2;
		res+=1ll*n*n;
		res+=1ll*n*minn-1ll*(minn+1)*(minn)/2;
		printf("%lld\n",res);
	}
	return 0;
}
