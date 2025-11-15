#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

constexpr const int N = 17;
mint ans[N], cnt[1<<N], f[1<<N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < 1<<n; ++i)
		cnt[i] = 1;
	for(int u, v; m--; ) {
		cin >> u >> v;
		--u; --v;
		for(int j = 0; j < 1 << n; ++j)
			if(j >> u & 1 && j >> v & 1)
				cnt[j] *= 2;
	}
	for(int i = 1; i < 1 << n; i += 2) {
		mint now = cnt[i];
		for(int j = i - 1; ~j; --j) {
			j &= i;
			now -= f[j] * cnt[i ^ j];
		}
		f[i] = now;
		for(int j = 1; j < n; ++j)
			if(i >> j & 1)
				ans[j] += now * cnt[(1 << n) - 1 ^ i];
	}
	for(int i = 1; i < n; ++i)
		cout << ans[i].val() << '\n';
	cout.flush(); return 0;
}
