#include <iostream>
#include <vector>
using namespace std;

const int N = 200003;
vector<int> G[N];
int fa[N], fans[N];

int fnd(const int& x) {
	if(x != fa[x])
		fa[x] = fnd(fa[x]);
	return fa[x];
}
/* https://atcoder.jp/contests/abc229/submissions/30255418 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	for(int _ = 0, u, v; _ < m; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans = 0;
	for(int u = n, x = 0, y = 0; u >= 2; --u) {
		++ans;
		for(const auto& v: G[u])
			if((x = fnd(u)) != (y = fnd(v))) {
				fa[y] = x;
				--ans;
			}
		fans[u] = ans;
	}
	for(int i = 2; i <= n + 1; ++i)
		cout << fans[i] << '\n';
	return 0;
}