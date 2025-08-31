#include <bits/stdc++.h>
using namespace std;

int a[23][23], n, P;
long long tot = 0, ans = 0;

void dfs(int x, int y) {
	tot = tot * 10 + a[x][y];
	if(x == n && y == n) {
		ans = max(ans, tot % P);
		tot /= 10; return;
	}
	if(y < n)
		dfs(x, y + 1);
	if(x < n)
		dfs(x + 1, y);
	tot /= 10;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> P;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> a[i][j];
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}
