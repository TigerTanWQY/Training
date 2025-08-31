#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 20 + 1;
int s[1 << N], f[1 << N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> s[1 << i - 1];
	cin >> m;
	for(int i = 1, x = 1 << n; i <= m; ++i, x <<= 1) {
		cin >> s[x];
		s[x] = -s[x];
	}
	int t = (1 << n + m) - 1;
	for(int i = 1; i <= t; ++i) {
		s[i] = s[i & -i] + s[i ^ (i & -i)];
		for(int j = 1; j <= n + m; ++j)
			if(i & 1 << j - 1)
				f[i] = max(f[i], f[i - (1 << j - 1)]);
		f[i] += !s[i];
	}
	cout << n + m - f[t] * 2;
	cout.flush();
	return 0;
}