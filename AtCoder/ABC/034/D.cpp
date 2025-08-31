#include <bits/stdc++.h>
using namespace std;

struct Liquid
{ int p, w; double g; }
a[1003];
int n, k;

bool chk(double x) {
	for(int i = 1; i <= n; ++i)
		a[i].g = (a[i].p - x) * a[i].w;
	sort(a + 1, a + n + 1, [](const Liquid& A, const Liquid& B)
	{ return A.g > B.g; });
	double res = 0;
	for(int i = 1; i <= k; ++i)
		res += a[i].g;
	return res >= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].w >> a[i].p;
	double L = 0, R = 100;
	for(int _ = 1000; _--; ) {
		double M = (L + R) / 2;
		if(chk(M))
			L = M;
		else
			R = M;
	}
	cout << fixed << setprecision(9) << L << endl;
	return 0;
}
