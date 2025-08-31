#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
tuple<int, int, int> e[N];
int fa[N];

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[i] = {w, u, v};
	}
	sort(e + 1, e + 1 + m);
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	int ans = 0;
	for(int i = 1, j = i; i <= m; i = j) {
		for(; get<0>(e[i]) == get<0>(e[j]); ++j);
		for(int k = i; k < j; ++k)
			if(fnd(get<1>(e[k])) != fnd(get<2>(e[k])))
				++ans;
		for(int k = i; k < j; ++k) {
			int fu = fnd(get<1>(e[k])), fv = fnd(get<2>(e[k]));
			if(fu == fv)
				continue;
			fa[fv] = fu;
			--ans;
		}
	}
	cout << ans << endl;
	return 0;
}