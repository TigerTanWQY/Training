#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e4 + 3;
vector<pair<int, int>> que[N];
int a[N], vis[1000003], c[N], ans[200003], n;

int lb(int x)
{ return x & -x; }

void mdf(int x, int w) {
	for(; x <= n; x += lb(x))
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
	int _q;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> _q;
	for(int i = 0, L, R; i < _q; ++i) {
		cin >> L >> R;
		que[R].push_back({L, i});
	}
	for(int i = 1; i <= n; ++i) {
		if(vis[a[i]])
			mdf(vis[a[i]], -1);
		vis[a[i]] = i; mdf(vis[a[i]], 1);
		int nw = qry(i);
		for(const auto& [x, id]: que[i])
			ans[id] = nw - qry(x - 1);
	}
	for(int i = 0; i < _q; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}
