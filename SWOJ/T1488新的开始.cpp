#include <iostream>
#include <algorithm>
using namespace std;

const int N = 303;
struct Node {
	int u, v, w;
	bool operator<(const Node& A) const
	{ return w < A.w; }
} e[2 * N * N];
int fa[N], n, m = 0, ans = 0;

int find(const int& x) {
	if(fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}

bool Kruskal() {
	int cnt = 0;
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	for(int i = 1; i <= m; ++i) {
		int u = find(e[i].u), v = find(e[i].v);
		if(u != v) {
			fa[u] = v;
			ans += e[i].w;
			++cnt;
		}
	}
	return cnt == n - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int v = 1, w; v <= n; ++v) {
		cin >> w;
		e[++m] = {0, v, w};
	}
	for(int u = 1; u <= n; ++u)
		for(int v = 1, w; v <= n; ++v) {
			cin >> w;
			if(u != v) {
				e[++m] = {u, v, w};
				e[++m] = {v, u, w};
			}
		}
	Kruskal();
	cout << ans;
	return 0;
}