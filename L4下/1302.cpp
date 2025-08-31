#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;

const double eps = 1e-10;
const int N = 53;
int n;
double r[N][N], a[N][N], b[N], f[N];

void gauss() {
	n -= 2;
	int l = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = l; j <= n; ++j)
			if(abs(a[j][i]) > abs(a[l][i])) {
				for(int k = i; k <= n; ++k)
					swap(a[l][k], a[j][k]);
				swap(b[l], b[j]);
			}
		if(abs(a[l][i]) < eps)
			continue;
		for(int j = 1; j <= n; ++j)
			if(j != l && abs(a[j][i]) > eps) {
				double delta = a[j][i] / a[l][i];
				for(int k = i; k <= n; ++k)
					a[j][k] -= a[l][k] * delta;
				b[j] -= b[l] * delta;
			}
		++l;
	}
	f[1] = 1;
	f[n + 2] = 0;
	for(int i = 1; i <= n; ++i)
		f[i + 1] = b[i] / a[i][i];
	n += 2;
	double x = 0;
	for(int i = 2; i <= n; ++i)
		if(abs(r[1][i]) >= eps)
			x += (f[1] - f[i]) * r[1][i];
	cout << fixed << setprecision(6) << 1.0 / x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		r[u][v] += 1.0 / w;
		r[v][u] += 1.0 / w;
	}
	for(int u = 2; u < n; ++u)
		for(int v = 1; v <= n; ++v)
			if(abs(r[u][v]) >= eps) {
				if(v == 1)
					b[u - 1] += r[u][v];
				else if(v < n)
					a[u - 1][v - 1] -= r[u][v];
				a[u - 1][u - 1] += r[u][v];
			}
	gauss();
	cout.flush();
	return 0;
}