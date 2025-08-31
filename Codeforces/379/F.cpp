#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
vector<int> G[N];
int dep[N], fa[30][N];

void upd(int u, int v) {
    fa[0][v] = u;
    dep[v] = dep[u] + 1;
    for(int i = 1; 1 << i <= dep[v]; ++i)
        fa[i][v] = fa[i - 1][fa[i - 1][v]];
}

int LCA(int u, int v) {
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = 25; i >= 0; --i)
        if(dep[u] - (1 << i) >= dep[v])
			u = fa[i][u];
    if(u == v)
		return u;
    for(int i = 25; i >= 0; --i)
        if(fa[i][u] != fa[i][v]) {
			u = fa[i][u];
			v = fa[i][v];
        }
    return fa[0][u];
}

int dis(int u, int v) {
    int p = LCA(u, v);
    return dep[u] - dep[p] + dep[v] - dep[p];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	G[1].push_back(2); G[1].push_back(3); G[1].push_back(4);
	fa[0][2] = fa[0][3] = fa[0][4] = 1;
	dep[1] = 1; dep[2] = dep[3] = dep[4] = 2;
	int m = 4, A = 2, B = 3, ans = 2, _q;
	cin >> _q;
	for(int u; _q--; cout.put('\n')) {
		cin >> u;
		G[u].push_back(++m); upd(u, m);
		G[u].push_back(++m); upd(u, m);
		int cur1 = m, tmp = dis(cur1, A);
		if(tmp > ans)
		{ ans = tmp; B = cur1; }
		tmp = dis(cur1, B);
		if(tmp > ans)
		{ ans = tmp; A = cur1; }
		cout << ans;
	}
	cout.flush(); return 0;
}
