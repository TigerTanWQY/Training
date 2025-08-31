#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int w[N], dis[N];

void bfs(int rt) {
	queue<int> q;
	q.push(rt);
	memset(dis, 0, sizeof(dis));
	dis[rt] = 1 + w[rt];
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!dis[v]) {
				dis[v] = dis[u] + w[v];
				q.push(v);
			}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		int rt = 0, m = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> w[i];
			if(w[i])
			{ rt = i; ++m; }
		}
		for(int _ = 1, u, v; _ < n; ++_) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bfs(rt);
		bool flag = true;
		for(int i = 1; flag && i <= n; ++i)
			if(dis[i] - 1 == m) {
				cout << "Yes";
				flag = false;
			}
		if(flag)
			cout << "No";
	}
	cout.flush();
	return 0;
}
