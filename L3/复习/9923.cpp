#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N * 2];
int dis[N * 2];

inline void bfs(const int rt) {
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		const int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, Q;
	cin >> n >> m >> Q;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[(u << 1) - 1].push_back((v << 1) - 2);
		G[(u << 1) - 2].push_back((v << 1) - 1);
		G[(v << 1) - 1].push_back((u << 1) - 2);
		G[(v << 1) - 2].push_back((u << 1) - 1);
	}
	bfs(0);
	for(int id, L; Q--; cout.put('\n')) {
		cin >> id >> L;
		if(G[0].empty())
			cout << "No";
		else {
			const int u = (id << 1) - 2 + (L & 1);
			if(dis[u] <= L)
				cout << "Yes";
			else
				cout << "No";
		}
	}
	cout.flush();
	return 0;
}