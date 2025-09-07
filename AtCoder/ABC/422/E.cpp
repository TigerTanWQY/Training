#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL x[500003], y[500003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	mt19937_64 rd(random_device{}());
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	for(int _ = 0; _ < 100; _++) {
		int i = rd() % n, j = rd() % n;
		for(; j == i; j = rd() % n);
		LL a = y[j] - y[i],
			b = x[i] - x[j],
			c = x[j] * y[i] - x[i] * y[j];
		int cnt = 0;
		for(int k = 0; k < n; ++k)
			if(a * x[k] + b * y[k] + c == 0)
				++cnt;
		if(cnt >= (n + 1) / 2) {
			cout << "Yes\n" << a << ' ' << b << ' ' << c << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
