#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

constexpr const int N = 2e4 + 3;
vector<int> G[N];
int a[13], b[13], dis[N], n;

void bfs() {
	memset(dis, 0x3f, sizeof(dis));
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		dis[a[i]] = 0;
		q.push(a[i]);
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(dis[v] == 0x3f3f3f3f) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, q;
	cin >> n >> m >> q;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(; q--; cout.put('\n')) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		bfs();
		cin >> m;
		int ans = 0x3f3f3f3f;
		for(int v; m--; ) {
			cin >> v;
			ans = min(ans, dis[v]);
		}
		if(ans == 0x3f3f3f3f)
			ans = -1;
		cout << ans;
	}
	cout.flush();
	return 0;
}