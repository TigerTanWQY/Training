#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> e;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if(u > v)
			swap(u, v);
		e.push_back({u, v});
	}
	vector<pair<int, int>> E;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			E.push_back({i, j});
	const int k = E.size();
	set<pair<int, int>> st(cbegin(e), cend(e));
	vector<bool> b(k, false);
	for(int i = 0; i < k; ++i)
		if(st.find(E[i]) != cend(st))
			b[i] = true;
	vector<int> p;
	for(int i = 0; i < k - n; ++i)
		p.push_back(0);
	for(int i = 0; i < n; ++i)
		p.push_back(1);
	sort(begin(p), end(p));
	int ans = 1e9;
	do {
		vector<int> c(n + 1, 0);
		for(int i = 0; i < k; ++i)
			if(p[i] == 1) {
				auto [u, v] = E[i];
				++c[u]; ++c[v];
			}
		bool flg = true;
		for(int i = 1; i <= n; ++i)
			if(c[i] != 2) {
				flg = false;
				break;
			}
		if(!flg)
			continue;
		int cnt = 0;
		for(int i = 0; i < k; ++i)
			if(p[i] == 1 && b[i])
				++cnt;
		ans = min(ans, m + n - cnt * 2);
	} while(next_permutation(begin(p), end(p)));
	cout << ans << endl;
	return 0;
}
