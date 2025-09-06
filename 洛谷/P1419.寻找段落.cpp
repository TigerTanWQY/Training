#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
int b[N], q[N], n, s, t;
double a[N], tot[N];

bool chk(double x) {
	int L = 1, R = 0;
	for(int i = 1; i <= n; ++i)
		a[i] = b[i] - x;
	tot[0] = 0;
	for(int i = 1; i <= n; ++i)
		tot[i] = tot[i - 1] + a[i];
	for(int i = 1; i <= n; ++i) {
		if(i >= s) {
			for(; L <= R && tot[i - s] < tot[q[R]]; --R);
			q[++R] = i - s;
		}
		if(L <= R && q[L] < i - t)
			++L;
		if(L <= R && tot[i] - tot[q[L]] >= 0)
			return true;
	}
	return false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> s; t = n;
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	double L = -1e4, R = 1e4;
	for(int _ = 500; _--; ) {
		double M = (L + R) / 2;
		if(chk(M))
			L = M;
		else
			R = M;
	}
	cout << (long long) (1000 * L) << endl;
	return 0;
}
