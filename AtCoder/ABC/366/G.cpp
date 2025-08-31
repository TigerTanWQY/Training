#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 63;
bool a[N][N], b[N][N];
int n;
unsigned long long ans[N];

bool gauss(int n, int m) {
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= m; ++j)
			if(a[j][i]) {
				swap(a[j], a[i]);
				break;
			}
		if(!a[i][i])
			continue;
		for(int j = 1; j <= m; ++j)
			if(i != j && a[j][i])
				for(int k = i; k <= n + 1; ++k)
					a[j][k] ^= a[i][k];
	}
	return !a[m][n + 1];
}

bool work(int i) {
	memcpy(a, b, sizeof a);
	a[n + 1][i] = a[n + 1][n + 1] = true;
	if(!gauss(n, n + 1))
		return false;
	for(int j = 1; j <= n; ++j)
		if(a[j][n + 1])
			ans[j] |= 1ULL << (i - 1);
	return true;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		a[u][v] = a[v][u] = b[u][v] = b[v][u] = true;
	}
	for(int i = 1; i <= n; ++i)
		if(!work(i)) {
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes\n";
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl; return 0;
}
