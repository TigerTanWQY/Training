#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5, K = 2e1;
int n, k;
vector<int> ev[N + 10];
int dis[N + 10][K + 2][2], pre[N + 10][K + 2][2];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) {
		ev[i].clear();
		for (int j = 0; j < k; j ++ )
			dis[i][j][0] = dis[i][j][1] = pre[i][j][0] = pre[i][j][1] = 0x3f3f3f3f;
	}
	for (int u, v, i = 1; i < n; i ++ ) {
		cin >> u >> v;
		ev[u].push_back(v);
		ev[v].push_back(u);
	}
	dis[1][0][0] = pre[1][0][0] = 0;
	queue<array<int, 4>> que;
	que.push({1, 0, 0, 0});
	while (!que.empty()) {
		auto [u, c, d, f] = que.front();
		que.pop();
		for (auto v : ev[u]) {
			if (v != f || !c) {
				if (d + 1 < dis[v][(c + 1) % k][0] && u != pre[v][(c + 1) % k][1]) {
					dis[v][(c + 1) % k][0] = d + 1;
					pre[v][(c + 1) % k][0] = u;
					que.push({v, (c + 1) % k, d + 1, u});
				} else if (d + 1 < dis[v][(c + 1) % k][1] && u != pre[v][(c + 1) % k][0]) {
					dis[v][(c + 1) % k][1] = d + 1;
					pre[v][(c + 1) % k][1] = u;
					que.push({v, (c + 1) % k, d + 1, v});
				}
			}
		}
	}
	for (int i = 2; i <= n; i ++ )
		cout << (dis[i][0][0] == 0x3f3f3f3f ? -1 : dis[i][0][0] / k) << ' ';
	cout.put('\n');
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	while(_T--) solve();
	cout.flush(); return 0;
}
