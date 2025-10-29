#include <iostream>
using namespace std;

constexpr const int N = 1003;
int a[N], b[N], c[N], d[N], w[N][N], mnv[N][N], mxv[N][N], q[N], k;

void get_max(int a[], int f[], int m) {
	int hh = 0, tt = -1;
	for(int i = 1; i <= m; ++i) {
		for(; hh <= tt && i - q[hh] >= k; ++hh);
		for(; hh <= tt && a[i] >= a[q[tt]]; --tt);
		q[++tt] = i;
		f[i] = a[q[hh]];
	}
}
void get_min(int a[], int f[], int m) {
	int hh = 0, tt = -1;
	for(int i = 1; i <= m; i ++) {
		for(; hh <= tt && i - q[hh] >= k; ++hh);
		for(; hh <= tt && a[i] <= a[q[tt]]; --tt);
		q[++tt] = i;
		f[i] = a[q[hh]];
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> w[i][j];
	for(int i = 1; i <= n; ++i) {
		get_min(w[i], mnv[i], m);
		get_max(w[i], mxv[i], m);
	}
	int res = 1e9;
	for(int i = k; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			a[j] = mxv[j][i];
			b[j] = mnv[j][i];
		}
		get_max(a, c, n);
		get_min(b, d, n);
		for(int j = k; j <= n; ++j)
			res = min(res, c[j] - d[j]);
	}
	cout << res << endl;
	return 0;
}
