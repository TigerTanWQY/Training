#include <bits/stdc++.h>
using namespace std;

int a[2][23], n, ans = 0;

void dfs(int u, int t) {
	if(u > n) {
		if(t == (1 << (n + 1)) - 2)
			++ans;
		return;
	}
	if(((1 << a[0][u]) & t) == 0)
		dfs(u + 1, (1 << a[0][u]) | t);
	if(((1 << a[1][u]) & t) == 0)
		dfs(u + 1, (1 << a[1][u]) | t);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[0][i] >> a[1][i];
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
