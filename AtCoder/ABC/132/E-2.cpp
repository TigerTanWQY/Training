#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e5 + 3;
vector<int> G[N];
int dis[N];

auto chg = [](int x, int k)
{ return 3 * (x - 1) + k + 1; };

void bfs(int rt) {
	memset(dis, 0, sizeof(dis));
	dis[rt] = 1;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, S, T;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[chg(u, 0)].push_back(chg(v, 1));
		G[chg(u, 1)].push_back(chg(v, 2));
		G[chg(u, 2)].push_back(chg(v, 0));
	}
	cin >> S >> T;
	bfs(chg(S, 0));
	cout << (dis[chg(T, 0)]? (dis[chg(T, 0)] - 1) / 3: -1) << endl;
	return 0;
}
