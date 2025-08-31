#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
using PII = pair<long long, int>;

const int N = 200003;
vector<int> G[N];
bool vis[N];
int a[N];
long long d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int u, v; m--; ) {
		cin >> u >> v;
		d[u] += a[v];
		d[v] += a[u];
		G[u].push_back(v);
		G[v].push_back(u);
	}
	priority_queue<PII, vector<PII>, greater<PII>> q;
	for(int i = 1; i <= n; ++i)
		q.push({d[i], i});
	long long ans = 0;
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		ans = max(ans, d[u]);
		for(const auto &v: G[u])
			q.push({d[v] = d[v] - a[u], v});
	}
	cout << ans;
	return 0;
}
