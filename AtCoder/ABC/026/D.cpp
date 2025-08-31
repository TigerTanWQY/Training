#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, c;
	cin >> a >> b >> c;
	auto f = [&](double x) -> double
	{ return a * x + b * sin(c * x * acos(-1.0)); };
	double L = 0, R = INT_MAX;
	for(int _ = 100000; ~_; --_) { //! 一定要多跑几次！！！
		double M = (L + R) / 2;
		if(f(M) <= 100)
			L = M;
		else
			R = M;
	}
	cout << fixed << setprecision(12) << L << endl;
	return 0;
}
