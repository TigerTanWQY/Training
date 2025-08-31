#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int P = 998244353;
const int N = 200003;
int f[2][N], ans[N], pre[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int cnt = k, m = 0, x = 0;
	for(; x <= n; ++m)
		x += cnt++;
	for(int i = 1; i <= m; ++i) {
		memset(pre, 0, sizeof(pre));
		for(int j = 0; j <= n; ++j) {
			pre[j] = f[i - 1 & 1][j];
			if(j >= k + i - 1)
				pre[j] = (pre[j] + pre[j - k - i + 1]) % P;
		}
		for(int j = 0; j <= n; ++j)
			if(j >= k + i - 1)
				f[i & 1][j] = (f[i & 1][j] + pre[j - k - i + 1]) % P;
		memset(f[i - 1 & 1], 0, sizeof(f[i - 1 & 1]));
		for(int j = 1; j <= n; ++j)
			ans[j] = (ans[j] + f[i & 1][j]) % P;
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,MAXN=2e5+5;
void MOD(int &x)
{
	if(x>=mod)x-=mod;
}
int k,n,f[2][MAXN],sum[MAXN],ans[MAXN],pre[MAXN];
signed main()
{
	cin>>n>>k;
	f[0][0]=1;
	int cnt=k,m=0,x=0;
	while(x<=n)
	{
		x+=cnt;
		cnt++;
		m++;
	}
	for(int i=1;i<=m;i++)
	{
		memset(pre,0,sizeof(pre));
		for(int j=0;j<=n;j++)if(j>=(k+i-1))MOD(pre[j]=pre[j-(k+i-1)]+f[(i-1)&1][j]);else pre[j]=f[(i-1)&1][j];
		for(int j=0;j<=n;j++)if(j>=(k+i-1))MOD(f[i&1][j]+=pre[j-(k+i-1)]);//注意数组下标不能为负。
		memset(f[(i-1)&1],0,sizeof(f[(i-1)&1]));
		for(int j=1;j<=n;j++)MOD(ans[j]+=f[i&1][j]);
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
*/