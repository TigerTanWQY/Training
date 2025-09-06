#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 103;
int T[N], E[N], D[N], L[N];
LL f[N][20003];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n - 1; ++i)
		cin >> T[i];
	for(int i = 0; i < n; ++i)
		cin >> E[i];
	for(int i = 0; i < n; ++i)
		cin >> D[i];
	for(int i = 0; i < n; ++i)
		if(D[i] == 0)
			L[i] = m + 10;
		else
			L[i] = (E[i] + D[i] - 1) / D[i];
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for(int j = 1; j <= m; ++j) {
		int x = min(j, L[0]);
		LL v = 1LL * x * E[0] - 1LL * D[0] * (x - 1) * x / 2;
		f[0][j] = v;
	}
	for(int i = 1; i < n; ++i) {
		int j = T[i - 1];
		for(int s = 0; s <= m; ++s) {
			int mx = s - j;
			if(mx < 0)
				continue;
			mx = min(mx, L[i]);
			for(int x = 0; x <= mx; ++x) {
				int tt = s - j - x;
				if(tt < 0 || f[i - 1][tt] == -0x3f3f3f3f3f3f3f3f)
					continue;
				LL v = 1LL * x * E[i] - 1LL * D[i] * (x - 1) * x / 2;
				f[i][s] = max(f[i][s], f[i - 1][tt] + v);
			}
		}
	}
	LL ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			ans = max(ans, f[i][j]);
	cout << ans << endl;
	return 0;
}
