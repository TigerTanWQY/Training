#include <iostream>
#include <bitset>
#include <vector>
#include <queue>
using namespace std;

const int N = 30003;
vector<int> G[N];
bitset<N> f[N];
int d[N], n;

void topsort() {
	queue<int> q;
	for(int u = 1; u <= n; ++u)
		if(!d[u])
			q.push(u);
	for(int u = 1; u <= n; ++u)
		f[u][u] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u]) {
			f[v] |= f[u];
			if(!--d[v])
				q.push(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[v].push_back(u);
		++d[u];
	}
	topsort();
	for(int u = 1; u <= n; ++u)
		cout << f[u].count() << '\n';
	return 0;
}