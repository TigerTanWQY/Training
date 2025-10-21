#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 17, M = 1 << N - 1;
int n;
LL a[N], fa[N], nxt[N], f[M], cnt[M];

void solve() {
	memset(f, 0, sizeof f);
	f[0] = 1;
	for(int i = 0; i < (1 << n); ++i)
		for(int j = 1; j <= n; ++j) {
			if((i & (1 << j - 1)) != 0 || (a[j] & i) != a[j] || (nxt[j] != 0 && cnt[i] != nxt[j]) || (fa[cnt[i]] != 0 && fa[cnt[i]] != j))
				continue;
			if(f[i | (1 << j - 1)] < 1e18)
				f[i | (1 << j - 1)] += f[i];
		}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m; LL year;
	cin >> n >> year >> m;
	year -= 2000;
	for(int x, y; m--; ) {
		cin >> x >> y;
		a[y] |= (1 << x - 1);
	}
	cnt[0] = 1;
	for(int i = 1; i < (1 << n); ++i)
		cnt[i] = cnt[i >> 1] + (i & 1);
	for(int i = 1, j; i <= n; ++i) {
		for(j = 1; j <= n; ++j) {
			if(fa[j])
				continue;
			fa[j] = i; nxt[i] = j;
			solve();
			if(f[(1 << n) - 1] >= year)
				break;
			else {
				year -= f[(1 << n) - 1];
				fa[j] = 0;
			}
		}
		if(j > n) {
			cout << "The times have changed" << endl;
			return 0;
		}
		cout << j << ' ';
	}
	cout << endl; return 0;
}
