#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
vector<pair<int, int>> G[N];
int a[N];
LL s[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	LL ans = 0;
	stack<tuple<int, int, bool>> stk;
	stk.push({1, -1, false});
	while(!stk.empty()) {
		auto [u, p, vis] = stk.top();
		stk.pop();
		if(!vis) {
			stk.push({u, p, true});
			for(auto it = G[u].crbegin(); it != G[u].crend(); ++it) {
				int v = it->first;
				if(v != p)
					stk.push({v, u, false});
			}
		} else {
			s[u] = a[u - 1];
			for(const auto& [v, w]: G[u])
				if(v != p) {
					ans += abs(s[v]) * (LL)w;
					s[u] += s[v];
				}
		}
	}
	cout << ans << endl;
	return 0;
}
