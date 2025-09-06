#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, a[20][20], v[20];
LL ans;

void dfs(int d, LL tot) {
	if (d > n) {
		ans = max(ans, tot);
		return;
	}
	if (!v[d]) {
		v[d] = 1;
		for (int i = d + 1; i <= n; ++i)
			if (!v[i]) {
				v[i] = 1;
				dfs(d + 1, tot + a[i][d]);
				v[i] = 0;
			}
		v[d] = 0;
	}
	dfs(d + 1, tot);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
