#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
vector<int> G[N], c;
int a[N], dis[N], d[N], n;

void topsort() {
	queue<int, list<int> > q;
	q.push(0);
	c.push_back(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			if(!--d[v]) {
				q.push(v);
				c.push_back(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int m; cin >> n >> m; cout.put('\n')) {
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		for(int u, v; m--; ) {
			cin >> u >> v;
			G[u].push_back(v);
			++d[v];
		}
		for(int i = 1; i <= n; ++i)
			if(!d[i]) {
				G[0].push_back(i);
				++d[i];
			}
		topsort();
		memset(dis, -0x3f, sizeof(int) * (n + 1));
		dis[0] = 0;
		for(int i = 0; i <= n; ++i) {
			int u = c[i];
			for(int j = 0; j < G[u].size(); ++j) {
				int v = G[u][j];
				dis[v] = max(dis[v], dis[u] + a[v]);
			}
		}
		int ans = -0x3f3f3f3f;
		for(int i = 1; i <= n; ++i)
			if(G[i].empty())
				ans = max(ans, dis[i]);
		cout << ans;
		for(int i = 0; i <= n; ++i) {
			G[i].clear();
			d[i] = 0;
		}
		c.clear();
	}
	cout.flush();
	return 0;
}