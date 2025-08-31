#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 500003, M = N;
vector<int> G[N], subG[N];
pair<int, int> e[M];
int fa[N];
LL dis[N];

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if(x == y)
		return;
	fa[y] = x;
}

void bfs(const int rt) {
	dis[rt] = 1;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: subG[u])
			if(!dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, _q;
	cin >> n;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		e[i] = {u, v};
	}
	cin >> _q;
	LL ans = 0;
	for(int L, R; _q--; ) {
		cin >> L >> R;
		for(int i = 1; i <= n; ++i)
			fa[i] = i;
		for(int i = L; i <= min(R, n - 1); ++i) {
			auto [u, v] = e[i];
			subG[u].push_back(v);
			subG[v].push_back(u);
			mrge(u, v);
		}
		LL res = 0;
		for(int i = 1; i <= n; ++i)
			if(!dis[i]) {
				bfs(i);
				int u = i;
				for(int j = 1; j <= n; ++j)
					if(fnd(i) == fnd(j) && dis[j] > dis[u])
						u = j;
				for(int j = 1; j <= n; ++j)
					if(fnd(i) == fnd(j))
						dis[j] = 0;
				bfs(u);
				for(int j = 1; j <= n; ++j)
					if(fnd(i) == fnd(j) && dis[j] > dis[u])
						u = j;
				res = max(res, dis[u] - 1);
			}
		ans += res;
		for(int i = 1; i <= n; ++i)
			subG[i].clear();
		memset(dis, 0, sizeof(dis));
	}
	cout << ans;
	cout.flush();
	return 0;
}