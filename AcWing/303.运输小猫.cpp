#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3, M = 103;
int q[N];
long long sd[N], a[N], s[N], f[M][N];

long long y(int k, int i)
{ return f[i-1][k] + s[k]; }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, p;
	cin >> n >> m >> p;
	for(int i = 2; i <= n; ++i)
	{ cin >> sd[i]; sd[i] += sd[i-1]; }
	for(int i = 1, h, t; i <= m; ++i)
	{ cin >> h >> t; a[i] = t - sd[h]; }
	sort(a + 1, a + m + 1);
	for(int i = 1; i <= m; ++i)
		s[i] = s[i-1] + a[i];
	memset(f, 0x3f, sizeof f);
	for(int i = 0; i <= p; ++i)
		f[i][0] = 0;
	for(int i = 1; i <= p; ++i) {
		int hh = 0, tt = 0;
		for(int j = 1; j <= m; ++j) {
			while(hh < tt && y(q[hh+1], i) - y(q[hh], i) <=
					a[j] * (q[hh+1] - q[hh]))
				++hh;
			f[i][j] = j * a[j] - s[j] + y(q[hh], i) - a[j] * q[hh];
			while(hh < tt && (y(q[tt], i) - y(q[tt-1], i)) * (j - q[tt]) >=
					(y(j, i) - y(q[tt], i)) * (q[tt] - q[tt-1]))
				--tt;
			q[++tt] = j;
		}
	}
	cout << f[p][m] << endl;
	return 0;
}
