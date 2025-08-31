#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-10;
const int N = 103;
int n;
double a[N][N], b[N];

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
			if(j != l && abs(a[j][i]) > eps) {
				double delta = a[j][i] / a[l][i];
				for(int k = i; k <= n; ++k)
					a[j][k] -= a[l][k] * delta;
				b[j] -= b[l] * delta;
			}
		++l;
	}
	/*
	秩: l
	自由元: n - l + 1
	*/
	for(int i = l; i <= n; ++i)
		if(abs(b[i]) > eps) {
			// 无解
			return;
		}
	if(l <= n)
		; // 无穷多解
	else
		for(int i = 1; i <= n; ++i)
			cout << fixed << setprecision(10) << b[i] / a[i][i] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	;
	cout.flush();
	return 0;
}