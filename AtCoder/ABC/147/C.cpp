#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr const int N = 15 + 1;
vector<pair<int, bool>> a[N];
bitset<N> b;
int n, ans = 0;

void dfs(const int u) {
	if(u > n) {
		for(int i = 1; i <= n; ++i)
			if(b[i])
				for(const auto& [v, w]: a[i])
					if(w ^ b[v])
						return;
		ans = max(ans, (int)b.count());
		return;
	}
	b[u] = true;
	dfs(u + 1);
	b[u] = false;
	dfs(u + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1, m; i <= n; ++i) {
		cin >> m;
		for(int x, y; m--; ) {
			cin >> x >> y;
			a[i].push_back({x, y});
		}
	}
	dfs(1);
	cout << ans;
	cout.flush();
	return 0;
}