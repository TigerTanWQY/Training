#include<bits/stdc++.h>
using namespace std;

constexpr const int N = 503;
int f[N][N], a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[i][i] = 1;
	for(int i = 1; i < n; ++i)
		f[i][i + 1] = 1 + (a[i] != a[i + 1]);
	for(int i = 3; i <= n; ++i)
		for(int j = 1; i + j - 1 <= n; ++j) {
			int L = j, R = i + j - 1;
			if(a[L] == a[R])
				f[L][R] = f[L + 1][R - 1];
			for(int k = L; k < R; ++k)
				f[L][R] = min(f[L][R], f[L][k] + f[k + 1][R]);
		}
	cout << f[1][n] << endl;
	return 0;
}
