#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[200003], tot = 0, ans = 0;
int n, k;

void dfs(int p, int cnt, LL res) {
	if(cnt == k) {
		ans = max(ans, res);
		return;
	}
	for(int i = p; i <= n; ++i)
		dfs(i + 1, cnt + 1, res ^ a[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot ^= a[i];
	}
	if(k <= n - k)
		dfs(1, 0, 0);
	else {
		k = n - k;
		dfs(1, 0, tot);
	}
	cout << ans << endl;
	return 0;
}
