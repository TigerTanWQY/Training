#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
vector<int> G[N], op;
int x[N], fa[N], dep[N], sL[N], sR[N];

void bfs(int rt) {
	dep[rt] = 1;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		op.push_back(u);
		for(const auto& v: G[u]) {
			if(v == fa[u])
				continue;
			fa[v] = u;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	}
	reverse(op.begin(), op.end());
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		if(x[i] == 0 || x[i] == 2)
			sL[i] = 1;
		else
			sR[i] = 1;
	bfs(1);
	long long ans = 0;
	for(const auto& u: op) {
		if(u == 1)
			continue;
		int p = fa[u];
		sL[p] += sL[u];
		sR[p] += sR[u];
		ans += abs(sL[u] - sR[u]);
	}
	cout << ans << endl;
	return 0;
}
