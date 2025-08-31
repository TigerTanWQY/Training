#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 18 + 1;
bitset<N * N * 4> G[N * N * 4];
int a[5][N][N * 2], cnt[N * N * 4];
LL f[N * N * 4][5][N * N * 4], g[N * N * 4][5], ans = 0;

void adde(const int u, const int v) {
	if(!G[u][v]) {
		G[u][v] = true;
		g[u][++cnt[u]] = v;
	}
	if(!G[v][u]) {
		G[v][u] = true;
		g[v][++cnt[v]] = u;
	}
}

LL dp(const int u, const int L1, const int R1) {
	int fa = 1;
	while(g[u][fa] != R1)
		++fa;
	if(f[u][fa][L1])
		return f[u][fa][L1];
	int L2, R2;
	if(L1 <= R1) {
		L2 = L1;
		R2 = R1 - 1;
	} else {
		L2 = R1 + 1;
		R2 = L1;
	}
	LL Lson = 0, Rson = 0;
	for(int k = 1; k <= 3; ++k)
		if(k != fa && L2 <= g[u][k] && g[u][k] <= R2)
			if(g[u][k] < u)
				Lson = max(Lson, dp(g[u][k], L2, u));
			else
				Rson = max(Rson, dp(g[u][k], R2, u));
	f[u][fa][L1] = Lson + Rson + 1;
	return f[u][fa][L1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int k = 1; k <= 4; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j < i * 2; ++j)
				cin >> a[k][i][j];
	for(int k = 1; k <= 4; ++k)
		for(int i = 2; i < n; ++i)
			for(int j = 2; j < i * 2 - 1; ++j) {
				adde(a[k][i][j], a[k][i][j - 1]);
				adde(a[k][i][j], a[k][i][j + 1]);
				if(j & 1)
					adde(a[k][i][j], a[k][i + 1][j + 1]);
				else
					adde(a[k][i][j], a[k][i - 1][j - 1]);
			}
	for(int k = 1; k <= 4; ++k)
		for(int i = 2; i < n * 2; i += 2) {
			adde(a[k][n][i], a[k][n][i - 1]);
			adde(a[k][n][i], a[k][n][i + 1]);
			adde(a[k][n][i], a[k][n - 1][i - 1]);
		}
	for(int i = 1; i < n * 2; ++i) {
		adde(a[1][n][i], a[4][n - i / 2][1]);
		adde(a[2][n][i], a[4][i / 2 + 1][(i / 2 + 1) * 2 - 1]);
		adde(a[3][n][i], a[4][n][n * 2 - i]);
	}
	for(int i = 1, j = 1; i <= n; ++i, ++j) {
		adde(a[1][i][1], a[3][i][i * 2 - 1]);
		adde(a[2][i][1], a[1][i][i * 2 - 1]);
		adde(a[3][i][1], a[2][i][i * 2 - 1]);
	}
	for(int i = 1; i <= 4 * n * n; ++i) {
		LL Lson = 0, Rson = 0;
		for(int j = 1; j <= 3; ++j)
			if(g[i][j] < i)
				Lson = max(Lson, dp(g[i][j], 1, i));
			else
				Rson = max(Rson, dp(g[i][j], 4 * n * n, i));
		ans = max(ans, Lson + Rson + 1);
	}
	cout << ans << endl;
	return 0;
}