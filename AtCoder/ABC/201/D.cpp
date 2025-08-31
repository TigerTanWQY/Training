#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2003;
char s[N][N];
int f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> (s[i] + 1);
	memset(f, 0x3f, sizeof(f));
	f[n][m] = 0;
	for(int i = n; i; --i)
		for(int j = m; j; --j) {
			if(i == n && j == m)
				continue;
			int x = f[i + 1][j], y = f[i][j + 1];
			x = (s[i + 1][j] == '+'? 1 - x: -1 - x);
			y = (s[i][j + 1] == '+'? 1 - y: -1 - y);
			f[i][j] = max(x, y);
		}
	if(f[1][1] > 0)
		cout << "Takahashi";
	else if(f[1][1] == 0)
		cout << "Draw";
	else
		cout << "Aoki";
	cout << endl;
	return 0;
}
