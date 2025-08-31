#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
#define _x first
#define _y second
/*
2
0.0 0.0
-1.0 1.0
1.0 0.0

0.500 1.500
*/
const double eps = 1e-10;
const int N = 13;
pair<double, double> pos[N];
int n;
double a[N][N], b[N];

double dis(const double& x1, const double& y1, const double& x2, const double& y2)
{ return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }

void gauss() {
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
			if(j != l && abs(a[j][i]) >= eps) {
				double delta = a[j][i] / a[l][i];
				for(int k = 1; k <= n; ++k)
					a[j][k] -= a[l][k] * delta;
				b[j] -= b[l] * delta;
			}
		++l;
	}
	for(int i = 1; i <= n; ++i)
		cout << fixed << setprecision(3) << b[i] / a[i][i] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 0; i <= n; ++i)
		cin >> pos[i]._x >> pos[i]._y;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			if(i != j) {
				pair<double, double> tpos{(pos[i]._x + pos[j]._x) / 2, (pos[i]._y + pos[j]._y) / 2};
			}
	gauss();
	cout.flush();
	return 0;
}