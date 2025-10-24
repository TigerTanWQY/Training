#include <bits/stdc++.h>
using namespace std;

constexpr const int INF = 0x3f3f3f3f;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		const int u = 1 << n;
		vector<int> sv, dl, h(u * 2, 0);
		vector<vector<int>> f(n + 1, vector<int>(u * 2, 0)),
			g(n + 1, vector<int>(u * 2, 0));
		for(int l = 0; l < n; ++l) {
			bool flg = false;
			for(int s = 0; s < u; ++s) {
				if(popcount((unsigned)s) == l) {
					sv.clear(); sv.push_back(0); dl.clear();
					for(int i = 0; i < n; ++i)
						if(s >> i & 1)
							dl.push_back(i);
						else
							sv.push_back(i);
					int uu = 1 << dl.size();
					for(int i = 0; i < uu; ++i) {
						h[i] = 0;
						for(int j = 0; j < (int)dl.size(); ++j)
							if(i >> j & 1)
								h[i] += a[dl[j]];
					}
					f[0][0] = 0;
					for(int i = 1; i < uu; ++i)
						f[0][i] = INF;
					for(int i = 1; i < (int)sv.size(); ++i)
						for(int j = 0; j < uu; ++j) {
							f[i][j] = INF;
							if(a[sv[i]] > f[i - 1][j]) {
								f[i][j] = a[sv[i]];
								g[i][j] = 0;
							} else
								for(int k = j; k; --k &= j)
									if(a[sv[i]] + h[k] > f[i - 1][j ^ k] &&
										a[sv[i]] + h[k] < f[i][j]) {
										f[i][j] = a[sv[i]] + h[k];
										g[i][j] = k;
									}
						}
					if(f[(int)sv.size() - 1][uu - 1] != INF) {
						flg = true;
						break;
					}
				}
			}
			if(flg) {
				cout << l << '\n';
				vector<int> p(n);
				for(int i = 1; i < n; ++i)
					p[i] = p[i - 1] + 1;
				int k = (1 << dl.size()) - 1;
				for(int i = (int)sv.size() - 1; i > 0; --i) {
					for(int j = 0; j < (int)dl.size(); ++j)
						if(g[i][k] >> j & 1) {
							cout << p[dl[j]] + 1 << ' ' << p[sv[i]] + 1 << '\n';
							for(int t = dl[j]; t < n; ++t)
								--p[t];
						}
					k ^= g[i][k];
				}
				break;
			}
		}
	}
	cout.flush(); return 0;
}
