#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

constexpr const int N = 200'003;
vector<int> G[N];
int fa[N], dep[N], sz[N], hson[N], dfn[N], top[N], rnk[N], idx = 0;

void dfs1(const int& u) { // 求子树大小
	hson[u] = -1;
	sz[u] = 1;
	for(const auto& v: G[u])
		if(!dep[v]) {
			dep[v] = dep[u] + 1;
			fa[v] = u;
			dfs1(v);
			sz[u] += sz[v];
			if(hson[u] == -1 || sz[v] > sz[hson[u]])
				hson[u] = v;
		}
}

void dfs2(const int& u, const int& t) {
	top[u] = t;
	dfn[u] = ++idx;
	rnk[idx] = u;
	if(hson[u] == -1)
		return;
	dfs2(hson[u], t);
	for(const auto& v: G[u])
		if(v != hson[u] && v != fa[u])
			dfs2(v, v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(hson, -1, sizeof(hson));
	cout.flush();
	return 0;
}