#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 6e5 + 3;
int f[23][N], a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int mx = 0;
	for(int i = 1, L, R; i <= n; ++i) {
		cin >> L >> R;
		a[L] = max(a[L], R);
		mx = max(mx, R);
	}
	for(int i = 1; i <= mx; ++i)
		a[i] = max(a[i], a[i - 1]);
	for(int i = 0; i <= mx; ++i)
		f[0][i] = a[i];
	for(int i = 1; i <= 20; ++i)
		for(int j = 0; j <= mx; ++j)
			f[i][j] = f[i - 1][f[i - 1][j]];
	for(int L, R; m--; cout.put('\n')) {
		cin >> L >> R;
		int ans = 0;
		for(int i = 20; i >= 0; --i)
			if(f[i][L] < R) {
				ans += 1 << i;
				L = f[i][L];
			}
		cout << (a[L] >= R? ans + 1: -1);
	}
	cout.flush(); return 0;
}
