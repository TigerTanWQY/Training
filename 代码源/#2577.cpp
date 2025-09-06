#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
unordered_set<int> ans[N];
vector<int> c;
int a[N], id = 0;
LL n, k, g, d;

void dfs(int p, int w) {
	cout << p << ' ' << w << '\n';
	if(id == n)
		return;
	else if(p == d / n) {
		for(int _ = g; _--; ++id)
			for(const auto& x: c)
				ans[a[id]].insert(x);
		return;
	}
	for(int x = w + 1; x <= d / k; ++x) {
		c.push_back(x);
		dfs(p + 1, x);
		c.pop_back();
	}
}

int main() {
	freopen("ex_photo3.in", "r", stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m >> k;
	g = gcd(n, k); d = n * k / g;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	dfs(0, 0);
	for(int i = 1; i <= m; ++i)
		cout << ans[i].size() << ' ';
	cout << endl; return 0;
}
