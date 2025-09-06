#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 503;
int a[N], r[N];
LL f[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, l;
	cin >> n >> m >> l;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(!l) {
		cout.put('0') << endl;
		return 0;
	}
	for(int i = 0; i <= n - l; ++i) {
		LL s = 0;
		for(int k = 0; k < l; ++k)
			s += a[i + k];
		s %= m;
		r[i] = (m - s) % m;
	}
	vector<vector<LL>> G;
	for(int j = 0; j < l; ++j) {
		vector<int> c;
		for(int i = j; i < n; i += l)
			c.push_back(i);
		const int k = c.size();
		vector<LL> D(k, 0);
		for(int i = 1; i < k; ++i) {
			int idx = c[i - 1];
			if(idx + 1 <= n - l) {
				int d = r[idx + 1] - r[idx];
				D[i] = D[i - 1] + d;
			}
		}
		vector<LL> cj(m, 0);
		for(int v0 = 0; v0 < m; ++v0) {
			LL tot = 0;
			for(int i = 0; i < k; ++i) {
				LL val = v0 + D[i], res = val % m;
				if(res < 0)
					res += m;
				tot += res;
			}
			cj[v0] = tot;
		}
		G.push_back(cj);
	}
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for(int j = 0; j < l; ++j)
		for(int s = 0; s < m; ++s) {
			if(f[j][s] == 0x3f3f3f3f3f3f3f3f)
				continue;
			for(int v = 0; v < m; ++v) {
				int ts = (s + v) % m;
				if(f[j][s] + G[j][v] < f[j + 1][ts])
					f[j + 1][ts] = f[j][s] + G[j][v];
			}
		}
	cout << f[l][r[0]] << endl;
	return 0;
}
