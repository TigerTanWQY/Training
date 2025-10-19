#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
vector<int> G[N];
int dis1[N], dis2[N], dis3[N];

void bfs(int rt, int dis[]) {
	queue<int> q;
	q.push(rt);
	dis[rt] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!~dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(dis1, -1, sizeof dis1);
	bfs(1, dis1);
	int d1 = 1;
	for(int i = 1; i <= n; ++i)
		if(dis1[i] >= dis1[d1])
			d1 = i;
	memset(dis2, -1, sizeof dis2);
	bfs(d1, dis2);
	int d2 = d1;
	for(int i = 1; i <= n; ++i)
		if(dis2[i] >= dis2[d2])
			d2 = i;
	memset(dis3, -1, sizeof dis3);
	bfs(d2, dis3);
	for(int i = 1; i <= n; cout.put('\n'), ++i)
		if(dis2[i] > dis3[i])
			cout << d1;
		else if (dis2[i] < dis3[i])
			cout << d2;
		else
			cout << max(d1, d2);
	cout.flush(); return 0;
}
