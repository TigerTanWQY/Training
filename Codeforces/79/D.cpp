#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5, M = 11, K = 103;
bool a[N];
int b[N], q[N * 2][3], dis[K * 2][N], Q[N], f[N * K];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1, x; i <= m; ++i) {
		cin >> x;
		a[x] = true;
	}
	for(int i = 1; i <= k; ++i)
		cin >> b[i];
	for(int i = 0; i <= n; ++i)
		a[i] = a[i] ^ a[i + 1];
	int tot = 0;
	for(int i = 0; i <= n; ++i)
		if(a[i]) {
			q[tot][0] = tot;
			q[tot][1] = i;
			++tot;
		}
	for(int i = 0; i < tot; ++i) {
		for(int j = 0; j <= n; ++j)
			dis[q[i][0]][j] = 0x3f3f3f3f;
		dis[q[i][0]][q[i][1]] = 0;
		int L = 1, R = 1;
		Q[1] = q[i][1];
		for(; L <= R; ++L) {
			int u = Q[L];
			for(int j = 1; j <= k; ++j) {
				if(u-b[j] >= 0 && dis[q[i][0]][u] + 1 < dis[q[i][0]][u-b[j]]) {
					dis[q[i][0]][u-b[j]] = dis[q[i][0]][u] + 1;
					Q[++R] = u - b[j];
				}
				if(u+b[j] <= n && dis[q[i][0]][u] + 1 < dis[q[i][0]][u+b[j]]) {
					dis[q[i][0]][u+b[j]] = dis[q[i][0]][u] + 1;
					Q[++R] = u + b[j];
				}
			}
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	int maxn = (1<<tot) - 1;
	for(int i = 0; i <= maxn; ++i) {
		int x = 0;
		for(; i >> x & 1; ++x);
		for(int y = x+1; y < tot; ++y)
			if(!(i >> y & 1))
				f[i | (1 << x) | (1 << y)] = min(f[i | (1 << x) | (1 << y)], f[i] + dis[x][q[y][1]]);
	}
	cout << (f[maxn] == 0x3f3f3f3f? -1: f[maxn]) << endl;
	return 0;
}
