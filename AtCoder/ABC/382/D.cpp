#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> a;
int n, m;

void dfs(int x) {
	if(x == n) {
		ans.push_back(a);
		return;
	}
	for(int i = 1; i <= m - (n - x - 1) * 10; ++i)
		if(x == 0 || a[x - 1] + 10 <= i) {
			a[x] = i;
			dfs(x + 1);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	a.resize(n);
	dfs(0);
	cout << ans.size() << '\n';
	for(const auto& p: ans) {
		for(const auto& x: p)
			cout << x << ' ';
		cout.put('\n');
	}
	cout.flush();
	return 0;
}
