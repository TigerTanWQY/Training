#include <bits/stdc++.h>
#define rep(i, l, r) for(i=l; i<=r; ++i)
using namespace std;

const int N=1505, inf=1e9;
vector<int> e[N], t[N];
int dis[N], q[N], c[N];
int qt, n, m, i, j, l, r, mid, u, v, tot;

void print(int x)
{ for(auto pt : t[x]) printf("%d ", pt); }
inline void prinT(int x) {
	int i; for(i=n-1; i>=x; --i) print(i);
	return ;
}
inline void cprint(int x)
{ tot+=t[x].size(); }
inline void cprinT(int x) {
	int i; for(i=n-1; i>=x; --i) cprint(i);
	return ;
}
int main() {
	scanf("%d", &qt);
	while(qt--) {
		scanf("%d %d", &n, &m); rep(i, 1, n) e[i].clear();
		rep(i, 1, m) {
			scanf("%d %d", &u, &v);
			e[v].emplace_back(u);
		}
		q[l=r=1]=1;
		rep(i, 1, n)
			c[i]=inf;
		c[1]=0;
		while(l<=r) {
			mid=q[l]; ++l;
			for(auto nxt : e[mid])
				if(c[nxt]>c[mid]+1) {
					c[nxt]=c[mid]+1;
					q[++r]=nxt;
				}
		}
		rep(i, 1, n) if(c[i]==inf) {puts("INFINITE"); break;} if(i<=n) continue;
		rep(i, 1, n) t[i].clear();
		rep(i, 1, n) t[c[i]].emplace_back(i);
		tot=0; cprinT(1); ++tot; rep(i, 1, n) cprinT(i);
		puts("FINITE"); printf("%d\n", tot);
		prinT(1); printf("%d ", 1);
		rep(i, 1, n) prinT(i); puts("");
	}
	return 0;
}
