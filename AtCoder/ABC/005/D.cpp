#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 53;
int s[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> s[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			s[i][j] += s[i][j - 1];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			s[i][j] += s[i - 1][j];
	cin >> q;
	for(int m; q--; cout.put('\n')) {
		cin >> m;
		int res = 0;
		for(int i = 1; i <= m; ++i)
			for(int j = m / i; j; --j)
				for(int Lx = 1; Lx + i - 1 <= n; ++Lx)
					for(int Ly = 1; Ly + j - 1 <= n; ++Ly) {
						int Rx = Lx + i - 1, Ry = Ly + j - 1;
						res = max(res, s[Rx][Ry] - s[Rx][Ly - 1] - s[Lx - 1][Ry] + s[Lx - 1][Ly - 1]);
					}
		cout << res;
	}
	cout.flush();
	return 0;
}
