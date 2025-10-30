#include <bits/stdc++.h>
using namespace std;

constexpr const int dx[]{-1, 0, 1, 0, 0}, dy[]{0, 1, 0, -1, 0};
constexpr const int n = 5, N = n+n-1;
bool g[N][N], b[N][N];

void turn(int x, int y) {
	for(int i = 0; i < n; ++i) {
		int tx = x + dx[i], ty = y + dy[i];
		if(tx < 0 || tx >= n || ty < 0 || ty >= n)
			continue;
		g[tx][ty] ^= true;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(; _T--; cout.put('\n')) {
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) {
				char c;
				cin >> c;
				g[i][j] = c - '0';
			}
		int ans = 10;
		for(int op = 0; op < 32; ++op) {
			memcpy(b, g, sizeof g);
			int cnt = 0;
			for(int i = 0; i < n; ++i)
				if(op >> i & 1) {
					++cnt;
					turn(0, i);
				}
			for(int i = 0; i < n-1; ++i)
				for(int j = 0; j < n; ++j)
					if(!g[i][j]) {
						++cnt;
						turn(i+1, j);
					}
			bool flg = false;
			for(int j = 0; j < n; ++j)
				if(!g[n-1][j]) {
					flg = true;
					break;
				}
			if(!flg)
				ans = min(ans, cnt);
			memcpy(g, b, sizeof g);
		}
		if(ans > n+1)
			ans = -1;
		cout << ans;
	}
	cout.flush(); return 0;
}
