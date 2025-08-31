#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e4 + 3;
double f[N], g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = n - 1; ~i; --i) {
		g[i] = g[i + 1] + 1.0 * n / (n - i);
		f[i] = 1.0 * i / (n - i) * (g[i] + 1) + f[i + 1] + g[i + 1] + 1;
	}
	cout << fixed << setprecision(2) << f[0] << endl;
	return 0;
}
