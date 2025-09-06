#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e6 + 3;
LL a[N], cnt[N], f[N], g[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q; LL m;
	cin >> n >> m >> _q;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	LL L = n + 1;
	for(int i = 1; i <= n; ++i) {
		cnt[i] = cnt[i - 1];
		f[i] = f[i - 1];
		g[i] = g[i - 1];
		if(a[i - 1] > 0) {
			++cnt[i];
			f[i] += a[i - 1];
		} else
			g[i] += (-a[i - 1]);
		if(g[i] >= m && L == n + 1)
			L = i;
	}
	for(LL x; _q--; cout.put('\n')) {
		cin >> x;
		LL lw = 1, hg = n, res = n + 1;
		while(lw <= hg) {
			LL M = (lw + hg) >> 1;
			if(cnt[M] * x + f[M] >= m) {
				res = M;
				hg = M - 1;
			} else
				lw = M + 1;
		}
		LL id = min(L, res);
		if(id > n)
			cout << "Tie";
		else if (g[id] >= m)
			cout << "No";
		else
			cout << "Yes";
	}
	cout.flush(); return 0;
}
