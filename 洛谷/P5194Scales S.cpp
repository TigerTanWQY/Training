#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 1003;
int a[N], n, c;
LL tot[N], ans;

void dfs(const int& u, const LL& s) {
	if(s > c)
		return;
	if(tot[u - 1] + s <= c) {
		ans = max(ans, tot[u - 1] + s);
		return;
	}
	ans = max(ans, s);
	for(int i = 1; i < u; ++i)
		dfs(i, s + a[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> c;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot[i] = tot[i - 1] + a[i];
	}
	dfs(n + 1, 0);
	cout << ans;
	return 0;
}