#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 1, K = (1 << 18) - 1, N = 1e5 + 3, M = 20;
bool vis[N];
int id[M], lim[M], g[K], a[M][M], n, ed;
LL f[M][K];

void init(int x) {
	for(int i = 1; i < M; ++i) {
		if(i == 1)
			a[i][1] = x;
		else
			a[i][1] = a[i - 1][1] * 3;
		if(a[i][1] > n)
			break ;
		ed = i;
		id[i] = 1;
		vis[a[i][1]] = true;
		for(int j = 2; j < M; ++j) {
			a[i][j] = a[i][j - 1] * 2;
			if(a[i][j] > n)
				break;
			id[i] = j;
			vis[a[i][j]] = true;
		}
		lim[i] = (1 << id[i]) - 1;
	}
}

LL solve() {
	LL res = 0;
	for(int i = 0; i <= lim[1]; ++i)
		f[1][i] = g[i];
	for(int i = 2; i <= ed; ++i)
		for(int j = 0; j <= lim[i]; ++j) {
			if(!g[j])
				continue ;
			f[i][j] = 0;
			for(int k = 0; k <= lim[i - 1]; ++k)
				if(g[k] && ((k & j) == 0))
					f[i][j] = (f[i][j] + f[i - 1][k]) % P;
		}
	for(int i = 0; i <= lim[ed]; ++i)
		res = (res + f[ed][i]) % P;
	return res;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n;
	LL ans = 1;
	for(int i = 0; i < K; ++i)
		g[i] = (i << 1 & i)? 0: 1;
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			init(i);
			ans = ans * solve() % P;
		}
	cout << ans << endl;
	return 0;
}
