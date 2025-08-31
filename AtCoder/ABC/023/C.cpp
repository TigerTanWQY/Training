#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
unordered_set<int> f[N];
vector<int> G[N];
int cnt[2][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R, C, k, n;
	cin >> R >> C >> k >> n;
	for(int i = 1, u, v; i <= n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		++cnt[0][u]; ++cnt[1][v];
	}
	for(int j = 1; j <= C; ++j)
		f[cnt[1][j]].insert(j);
	long long ans = 0;
	for(int i = 1; i <= R; ++i) {
		int w = k - cnt[0][i];
		if(w < 0)
			continue;
		ans += f[w].size();
		for(const auto& v: G[i]) {
			if(f[w].count(v))
				--ans;
			if(f[w + 1].count(v))
				++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
