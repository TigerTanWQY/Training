#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
double f[2][N][N], w[N][N], s[N];

struct Node {
	double x, y, v;
	bool operator<(const Node& A) const
	{ return x < A.x; }
} a[N];

int main() {
	int n; double m;
	cin >> n >> m;
	a[1] = {m, 0, 0};
	for(int i = 2; i <= n+1; ++i)
		cin >> a[i].x;
	for(int i = 2; i <= n+1; i++)
		cin >> a[i].y;
	for(int i = 2; i <= n+1; i++)
		cin >> a[i].v;
	sort(a+1, a+n+2);
	int L = 0, R = 0;
	for(int i = 1; i <= n+1; ++i) {
		s[i] = s[i-1] + a[i].v;
		if(fabs(a[i].x-m) <= 1e-12 && fabs(a[i].y) <= 1e-12)
			L = R = i;
	}
	for(int k = 0; k < 2; ++k)
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				f[k][i][j] = -0x7fffffffffffffff; // 必须选用极大值
	f[0][L][L] = f[1][R][R] = 0;
	for(int k = 1; k <= n+1; ++k)
		for(int i = 1; i+k <= n+1; ++i) {
			int j = i+k;
			f[0][i][j] = a[i].y + max(f[0][i+1][j] - (a[i+1].x - a[i].x) * (s[n+1] + s[i] - s[j]),
				f[1][i+1][j] - (a[j].x - a[i].x) * (s[n+1] + s[i] - s[j]));
			f[1][i][j] = a[j].y + max(f[1][i][j-1] - (a[j].x - a[j-1].x) * (s[n+1] + s[i-1] - s[j-1]),
				f[0][i][j-1] - (a[j].x - a[i].x) * (s[n+1] + s[i-1] - s[j-1]));
		}
	cout << fixed << setprecision(3) << max(f[1][1][n+1], f[0][1][n+1]) / 1000;
	return 0;
}
