#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e6 + 7, N = 500;
int C[N + 3][N + 3];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	C[0][0] = 1;
	for(int i = 0; i <= N; ++i) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}
	int _T;
	cin >> _T;
	for(int _ = 1, n, m, k; _ <= _T; cout.put('\n'), ++_) {
		cin >> n >> m >> k;
		int ans = 0;
		for(int S = 0; S < 16; ++S) {
			int cnt = 0, r = n, c = m;
			if(S & 1)
			{ --r; ++cnt; }
			if(S & 2)
			{ --r; ++cnt; }
			if(S & 4)
			{ --c; ++cnt; }
			if(S & 8)
			{ --c; ++cnt; }
			if(cnt & 1)
				ans = (ans + P - C[r * c][k]) % P;
			else
				ans = (ans + C[r * c][k]) % P;
		}
		cout << "Case " << _ << ": " << ans;
	}
	cout.flush(); return 0;
}
