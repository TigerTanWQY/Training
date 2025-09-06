#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e4 + 3;
vector<int> G[N];

int main() {
	freopen("worm.in", "r", stdin);
	freopen("worm.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout << endl;
	return 0;
}
