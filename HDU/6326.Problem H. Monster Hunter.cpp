#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
struct Node {
	LL x, y;
	int id;
	bool operator<(const Node& z) const	{
		if(x < y && z.x < z.y)
			return x > z.x;
		else if(y <= x && z.y <= z.x)
			return y < z.y;
		else
			return y <= x && z.y > z.x;
	}
} a[N];
__gnu_pbds::priority_queue<Node> q;
vector<int> G[N];
bitset<N> vis;
int fa[N];

void dfs(const int u) {
	for(const auto& v: G[u])
		if(v != fa[u]) {
			fa[v] = u;
			dfs(v);
		}
}

int fnd(const int u) {
	if(!vis[fa[u]])
		return fa[u];
	else
		return fa[u] = fnd(fa[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n;
		for(int i = 2; i <= n; ++i) {
			cin >> a[i].x >> a[i].y; a[i].id = i;
			q.push(a[i]);
		}
		a[1].x = a[1].y = a[1].id = 0;
		fa[1] = 1;
		for(int _ = 1, u, v; _ < n; ++_) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		while(!q.empty()) {
			auto u = q.top();
			q.pop();
			if(!(u.x == a[u.id].x && u.y == a[u.id].y) || vis[u.id])
				continue;
			int fu = fnd(u.id);
			auto v = a[fu];
			a[fu].x += max(a[fu].y, a[u.id].x) - a[fu].y;
			if(a[fu].y > a[u.id].x)
				a[fu].y -= a[u.id].x - a[u.id].y;
			else
				a[fu].y = a[u.id].y;
			if(fu != 1 && !(a[fu].x == v.x && a[fu].y == v.y))
				q.push(a[fu]);
			vis[u.id] = true;
		}
		cout << a[1].x << '\n';
		for(int i = 1; i <= n; ++i)
			G[i].clear();
		vis.reset();
	}
	cout.flush();
	return 0;
}