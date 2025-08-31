#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937_64 rd(random_device{}());
constexpr const int N = 100010, M = 105;
int a[N][M], b[M], c[N][M], q[N], id[N], m, P;

bool chk(int x, int y) {
	int tot = 0;
	for(int i = 1; i <= m; ++i)
		tot += a[x][i] * a[y][i];
	return !(tot % P);
}
int work(int x) {
	int ans = 0;
	if(P == 2)
		for(int i = 1; i <= m; b[i] ^= a[x][i], ++i)
			ans ^= b[i] & a[x][i];
	else
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= m; c[i][j] += a[x][i] * a[x][j], ++j)
				ans += c[i][j] * a[x][i] * a[x][j];
	return ans % P;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n >> m >> P;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{ cin >> a[i][j]; a[i][j] %= P; }
	iota(id + 1, id + n + 1, 1);
	for(int _ = 6; _--; ) {
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		shuffle(id + 1, id + n + 1, rd);
		for(int i = 1; i <= n; ++i)
			if(work(id[i]) != (i - 1) % P)
				for(int j = 1; j < i; ++j)
					if(chk(id[i], id[j])) {
						if(id[i] > id[j])
							swap(i, j);
						cout << id[i] << ' ' << id[j] << endl;
						return 0;
					}
		}
	cout << "-1 -1" << endl;
	return 0;
}
