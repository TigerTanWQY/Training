#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 63;
vector<int> G[N];
int w[N], v[N], f[32003], fa[N];

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> w[i] >> v[i] >> fa[i];
		v[i] *= w[i];
		if(fa[i])
			G[fa[i]].push_back(i);
	}
	for(int i = 1; i <= n; ++i) {
		if(fa[i])
			continue;
		for(int j = m; ~j; --j)
			for(int k = 0; k < 1<<G[i].size(); ++k) {
				int a = w[i], b = v[i];
				for(int t = 0; t < G[i].size(); ++t)
					if(k >> t & 1) {
						a += w[G[i][t]];
						b += v[G[i][t]];
					}
				if(j >= a)
					f[j] = max(f[j], f[j - a] + b);
			}
	}
	cout << f[m] << endl;
	return 0;
}
