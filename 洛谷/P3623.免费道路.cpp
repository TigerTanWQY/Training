#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> ans;
tuple<int, int, int> e[100'003];
int n, m, k, fa[20003], cnt;

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

inline bool mrge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if(x == y)
		return false;
	fa[y] = x;
	return true;
}

inline void init() {
	cnt = 0;
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
}

inline void check() {
	int of = fnd(1);
	for(int i = 2; i <= n; i++) {
		int nw = fnd(i);
		if(nw != of) {
			cout << "no solution" << endl;
			exit(0);
			return;
		}
		of = nw;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[i] = {w, u, v};
	}
	init();
	sort(e + 1, e + m + 1, greater<>());
	for(int i = 1; i <= m; ++i) {
		auto& [w, u, v] = e[i];
		if(mrge(u, v) && w == 0) {
			++cnt;
			w = -1;
		}
	}
	if(cnt > k) {
		cout << "no solution" << endl;
		return 0;
	}
	check();
	init();
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; ++i) {
		auto& [w, u, v] = e[i];
		int fu = fnd(u), fv = fnd(v);
		if(fu == fv)
			continue;
		if(w == 1 || cnt < k) {
			ans.push_back(e[i]);
			fa[fv] = fu;
			if(w < 1) {
				++cnt;
				w = 0;
			}
		}
	}
	if(cnt < k) {
		cout << "no solution" << endl;
		return 0;
	}
	check();
	for(auto& [w, u, v]: ans) {
		if(w == -1)
			w = 0;
		cout << u << ' ' << v << ' ' << w << '\n';
	}
	cout.flush();
	return 0;
}
