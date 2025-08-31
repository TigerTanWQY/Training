#include <iostream>
#include <cstdlib>
#include <vector>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 500'003;
struct Node {
	int u, sz;
	LL w;
	bool operator<(const Node& A) const
	{ return w * A.sz > A.w * sz; }
};
vector<int> G[N];
int a[N], fa[N], sz[N], cnt = 0;
LL w[N];

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void dfs(const int u, const int fau) {
	++cnt;
	for(const auto& v: G[u])
		if(v == fau) {
			cout << "-1";
			cout.flush();
			exit(0);
		} else
			dfs(v, u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		G[a[i]].push_back(i);
	}
	dfs(0, -1);
	if(cnt <= n) {
		cout << "-1";
		cout.flush();
		return 0;
	}
	for(int i = 0; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
	__gnu_pbds::priority_queue<Node> q;
	for(int i = 1; i <= n; ++i) {
		cin >> w[i];
		q.push({i, 1, w[i]});
	}
	LL ans = 0;
	while(!q.empty()) {
		auto f = q.top();
		q.pop();
		int u = fnd(f.u);
		if(u != f.u)
			continue;
		/* Begin Merge */
		int fau = fnd(a[u]);
		fa[u] = fau;
		ans += w[u] * sz[fau];
		w[fau] += w[u];
		sz[fau] += sz[u];
		/* End Merge */
		if(fau)
			q.push({fau, sz[fau], w[fau]});
	}
	cout << ans;
	cout.flush();
	return 0;
}