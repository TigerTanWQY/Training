#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e6 + 3;
struct Node
{ int id, x, v; };
vector<Node> q[N];
int a[N], c[N], ans[N];

int lb(int x)
{ return x & -x; }

void mdf(int x, int w = 1) {
	for(; x < N; x += lb(x))
		c[x] += w;
}

int qry(int x) {
	int res = 0;
	for(; x; x -= lb(x))
		res += c[x];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1, L, R, x; i <= m; ++i) {
		cin >> L >> R >> x;
		q[L - 1].push_back({i, x, -1});
		q[R].push_back({i, x, 1});
	}
	for(int i = 1; i <= n; ++i) {
		mdf(a[i]);
		for(const auto& [id, x, v]: q[i])
			ans[id] += v * qry(x);
	}
	for(int i = 1; i <= m; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}
