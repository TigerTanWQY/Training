#include<bits/stdc++.h>
using namespace std;

const int maxn=150;
int m,n;
int f[maxn],cnt[(1<<11)+3][(1<<11)+3];
int d[(1<<11)+3][(1<<11)+3];

int dp(int s,int a) {
	if(d[s][a]!=-1)
		return d[s][a];
	if(cnt[s][a]<=1)
		return d[s][a]=0;
	if(cnt[s][a]==2)
		return d[s][a]==1;
	int ans=20;
	for(int i=0; i<m; ++i)
		if(!(s&(1<<i)))
			ans=min(ans, max(dp(s|(1<<i),a),dp(s|(1<<i),a|(1<<i)))+1 );
	return d[s][a]=ans;
}

int main() {
	while(scanf("%d%d", &m, &n) && (m || n)) {
		memset(f,0,sizeof(f));
		char s[20];
		for(int i=1; i<=n; ++i) {
			scanf("%s",s);
			for(int j=0; j<m; ++j)
				f[i]|=((s[j]-'0')<<j);
		}
		memset(cnt,0,sizeof cnt);
		for(int i=0; i<(1<<m); ++i)
			for(int j=1; j<=n; ++j)
				++cnt[i][i&f[j]];
		memset(d,-1,sizeof d);
		printf("%d\n",!dp(0,0)?0:dp(0,0)+1);
	}
	return 0;
}
