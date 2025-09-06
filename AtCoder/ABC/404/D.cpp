#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 13, M = 103;
vector<int> a[M], G[N];
int cv[N], cs[M];
LL c[N], k[M];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	for(int i = 0; i < m; ++i) {
		cin >> k[i];
		a[i].resize(k[i]);
		for(int j = 0; j < k[i]; ++j)
			cin >> a[i][j];
	}
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < k[i]; ++j)
			G[a[i][j] - 1].push_back(i);
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int s = 0; s < 1 << n; ++s)
		for(int t = s; t >= 0; --t) {
			t &= s;
			memset(cv, 0, sizeof(cv));
			memset(cs, 0, sizeof(cs));
			LL cost = 0;
			for(int i = 0; i < n; ++i) {
				cv[i] += (s >> i) & 1;
				cv[i] += (t >> i) & 1;
				cost += cv[i] * c[i];
				for(int x: G[i])
					cs[x] += cv[i];
			}
			bool ok = true;
			for(int i = 0; ok && i < m; ++i)
				if(cs[i] < 2)
					ok = false;
			if(ok)
				ans = min(ans, cost);
		}
	cout << ans << endl;
	return 0;
}
