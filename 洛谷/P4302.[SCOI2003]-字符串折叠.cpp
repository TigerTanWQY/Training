#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 103;
int f[N][N], m[N];
string s;

bool chk(int L, int R, int len) {
	for(int i = L; i <= R; ++i)
		if(s[i] != s[(i - L) % len + L])
			return false;
	return true;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	int n = s.size();
	s = '$' + s;
	for(int i = 1; i <= 9; ++i)
		m[i] = 1;
	for(int i = 10; i <= 99; ++i)
		m[i] = 2;
	m[100] = 3;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[i][i] = 1;
	for(int L = 2; L <= n; ++L)
		for(int i = 1, j = i + L - 1; j <= n; ++i, ++j) {
			for(int k = i; k < j; ++k)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
			for(int k = i; k < j; ++k) {
				int len = k - i + 1;
				if(L % len != 0)
					continue;
				if(chk(i, j, len))
					f[i][j] = min(f[i][j], f[i][k] + 2 + m[L / len]);
			}
		}
	cout << f[1][n] << endl;
	return 0;
}
