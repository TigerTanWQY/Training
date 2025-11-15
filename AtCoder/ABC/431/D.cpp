#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 503;
int w[N], h[N], b[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> h[i] >> b[i];
		tot += w[i];
	}
	tot /= 2;
	vector<LL> f(tot+1, -1e18);
	f[0] = 0;
	LL base = accumulate(b, b+n, 0LL);
	for(int i = 0; i < n; ++i) {
		auto g = f;
		for(int j = 0; j <= tot; ++j)
			if(f[j] != -1e18) {
				int tw = j + w[i];
				if(tw <= tot) {
					LL nw = f[j] + (h[i] - b[i]);
					if(nw > g[tw])
						g[tw] = nw;
				}
			}
		f = move(g);
	}
	LL ans = base;
	for(int i = 0; i <= tot; ++i)
		if(f[i] != -1e18) {
			LL t = base + f[i];
			if(t > ans)
				ans = t;
		}
	cout << ans << endl;
	return 0;
}
