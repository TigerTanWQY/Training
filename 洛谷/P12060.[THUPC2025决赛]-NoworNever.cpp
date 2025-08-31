#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2003;
bitset<N> f[N], g[N], vis;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, _q;
	cin >> n >> m >> _q;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		bitset<N> x;
		for(int j = 0; j < m; ++j)
			if(s[j] == '1')
				x[j] = true;
		for(int j = 0; j < m; ++j)
			if(x[j])
				if(!vis[j]) {
					f[j] = x;
					vis[j] = true;
					break;
				} else
					x ^= f[j];
	}
	for(int i = m - 1; ~i; --i)
		if(vis[i])
			for(int j = i - 1; ~j; --j)
				if(f[j][i])
					f[j] ^= f[i];
	for(string s; _q--; cout.put('\n')) {
		cin >> s;
		bitset<N> x;
		for(int j = 0; j < m; ++j)
			if(s[j] == '1')
				x[j] = true;
		for(int j = m - 1; ~j; --j) {
			g[j] = g[j + 1];
			if(x[j] && vis[j])
				g[j] ^= f[j];
		}
		for(int j = 0; j < m; ++j) {
			auto y = x ^ g[j];
			if(!(y >> j).any()) {
				for(int k = j; k < m; ++k)
					x[k] = false;
				break;
			}
			if(vis[j] && !x[j])
				x ^= f[j];
		}
		for(int i = 0; i < m; ++i)
			cout << x[i];
	}
	cout.flush(); return 0;
}
