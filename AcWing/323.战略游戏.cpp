#include <bits/stdc++.h>
using namespace std;

vector<int> G[1503];
int f[1503][3];

void DP(int u, int fa) {
	f[u][0] = 0; f[u][1] = 1;
	for(const auto& v: G[u]) {
		if(v == fa)
			continue;
		DP(v, u);
		f[u][1] += min(f[v][0], f[v][1]);
		f[u][0] += f[v][1];
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int n; cin >> n; cout.put('\n')) {
		for(int i = 1, x, k; i <= n; ++i) {
			cin >> x; cin.get(); cin.get(); cin >> k;
			cin.get(); ++x;
			for(int y; k--; ) {
				cin >> y; ++y;
				G[x].push_back(y);
				G[y].push_back(x);
			}
		}
		DP(1, 0);
		cout << min(f[1][0], f[1][1]);
		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}
	cout.flush(); return 0;
}
