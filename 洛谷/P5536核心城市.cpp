#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 100003;
vector<int> G[N];
int d[N], n;

void bfs(const int& root) {
	for(int i = 1; i <= n; ++i)
		d[i] = 0;
	d[root] = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!d[v]) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> n >> k;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(1);
	int u = 1;
	for(int v = 2; v <= n; ++v)
		if(d[v] > d[u])
			u = v;
	bfs(u);
	u = 1;
	for(int v = 2; v <= n; ++v)
		if(d[v] > d[u])
			u = v;
	bfs(u);
	cout << max(1, (d[u] - k) / 2 + !!(d[u] - k));
	return 0;
}