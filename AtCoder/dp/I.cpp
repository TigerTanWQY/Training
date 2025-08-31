#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3003;
long long f[N][N], s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
		f[i][i] = x;
	}
	for(int i = n - 1; i; --i)
		for(int j = i + 1; j <= n; ++j)
			f[i][j] = max(s[j] - s[i - 1] - f[i + 1][j],
			s[j] - s[i - 1] - f[i][j - 1]);
	cout << f[1][n] * 2 - s[n] << endl;
	return 0;
}
