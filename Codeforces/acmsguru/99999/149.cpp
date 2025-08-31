#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 10'003;
vector<pair<int, int>> G[N];
int f[N][3];

void up(const int u, const int fa) {
	f[u][0] = f[u][1] = 0;
	for(const auto& [v, w]: G[u])
		if(v != fa) {
			up(v, u);
			if(f[u][1] < f[v][0] + w)
				f[u][1] = f[v][0] + w;
			if(f[u][0] < f[u][1])
				swap(f[u][0], f[u][1]);
		}
}

void down(const int u, const int fa) {
	for(const auto& [v, w]: G[u])
		if(v != fa) {
			f[v][2] = f[u][2] + w;
			if(f[v][0] + w == f[u][0])
				f[v][2] = max(f[v][2], f[u][1] + w);
			else
				f[v][2] = max(f[v][2], f[u][0] + w);
			down(v, u);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int u = 2, v, w; u <= n; ++u) {
		cin >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	up(1, 0);
	f[0][2] = 0;
	down(1, 0);
	for(int i = 1; i <= n; i++)
		cout << max(f[i][2], f[i][0]) << '\n';
	return 0;
}