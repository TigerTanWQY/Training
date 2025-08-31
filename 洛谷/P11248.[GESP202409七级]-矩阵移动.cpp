#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 503;
char s[N][N];
int f[N][N][2];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m, K; _T--; cout.put('\n')) {
		cin >> n >> m >> K;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> s[i][j];
		for(int k = 0; k <= K; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= m; ++j)
					f[i][j][k & 1] = ((k && s[i][j] == '?')?
						max({f[i - 1][j][k & 1], f[i][j - 1][k & 1],
							max(f[i - 1][j][!(k & 1)], f[i][j - 1][!(k & 1)]) + 1}):
						max(f[i - 1][j][k & 1], f[i][j - 1][k & 1]) + (s[i][j] == '1'));
		cout << f[n][m][K & 1];
	}
	cout.flush();
	return 0;
}
