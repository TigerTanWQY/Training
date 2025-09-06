#include <bits/stdc++.h>
using namespace std;

constexpr const int EPS = 50000;
int a[13], b[13];
long long f[2][100003], s[100003];

int main() {
	freopen("sumsol.in", "r", stdin);
	freopen("sumsol.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	int flg = 0;
	f[flg][EPS] = 1;
	int mn = 0, mx = 0;
	for(int i = 0; i < n; ++i) {
		s[0] = f[flg][0];
		for(int j = 1; j < n; ++j)
			s[j] = s[j - 1] + f[flg][j];
		int nxt = 1 - flg;
		memset(f[nxt], 0, sizeof(f[nxt]));
		int tmn = mn + a[i], tmx = mx + b[i];
		for(int j = tmn + EPS; j <= tmx + EPS; ++j) {
			int L = j - b[i], R = j - a[i];
			L = max(L, 0); R = min(R, n - 1);
			if(L <= R)
				if(L == 0)
					f[nxt][j] = s[R];
				else
					f[nxt][j] = s[R] - s[L - 1];
			else
				f[nxt][j] = 0;
		}
		mn = tmn; mx = tmx; flg = nxt;
	}
	cout << f[flg][m + EPS] << endl;
	return 0;
}
