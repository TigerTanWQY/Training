#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
int get_lower(ll x,int p) {
	int ass=0;
	while(x%p==0) {
		x/=p;
		ass++;
	}
	return ass;
}
ll n,k;
ll a[200+5];
ll dp[2][200+5][6000];
ll sum_two,sum_five,sum,ans;
ll cur;
inline void ready() {
	scanf("%d%d",&n,&k);
	for(ll i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	memset(dp,-1,sizeof(dp));
}
int main() {
	ready();
	dp[0][0][0]=0;
	for(ll i=1; i<=n; i++) {
		sum_two=get_lower(a[i],2);
		sum_five=get_lower(a[i],5);
		cur^=1;
		sum+=sum_two;
		for(ll j=0; j<=k&&j<=i; j++) {
			for(ll x=0; x<=sum; x++) {
				dp[cur][j][x]=max(dp[cur^1][j][x],dp[cur][j][x]);
				if(j>=1&&dp[cur^1][j-1][x-sum_two]>=0&&x-sum_two>=0)
					dp[cur][j][x]=max(dp[cur^1][j-1][x-sum_two]+sum_five,dp[cur][j][x]);
			}
		}
	}
	for(ll i=0; i<=sum; i++) {
		ans=max(ans,min(i,dp[cur][k][i]));
	}
	printf("%lld",ans);
	return 0;
}
