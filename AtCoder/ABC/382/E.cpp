#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5003;
double g[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, X;
	cin >> n >> X;
	g[0] = 1;
	for(int i = 1; i <= n; ++i) {
		double p;
		cin >> p; p /= 100;
		for(int j = i; j; --j)
			g[j] = g[j - 1] * p + g[j] * (1 - p);
		g[0] *= 1 - p;
	}
	for(int i = 0; i <= X; ++i) {
		for(int j = 1; j < i; ++j)
			f[i] += f[i - j] * g[j];
		f[i] = (f[i] + 1) / (1 - g[0]);
	}
	cout << fixed << setprecision(8) << f[X] << endl;
	return 0;
}
