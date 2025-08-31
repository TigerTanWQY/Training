#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int f[N][13], w[N], in[N], n;

void topSort() {
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		if(!in[i])
			q.push(i);
		f[i][w[i]] = 1;
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u]) {
			if(!--in[v])
				q.push(v);
			for(int i = 1; i <= w[v]; ++i)
				if(f[u][i] + 1 > f[v][w[v]])
					f[v][w[v]] = f[u][i] + 1;
			for(int i = 1; i <= 10; ++i)
				if(f[u][i] > f[v][i])
					f[v][i] = f[u][i];
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		++in[v];
	}
	topSort();
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= 10; ++j)
			ans = max(ans, f[i][j]);
	cout << ans << endl;
	return 0;
}
