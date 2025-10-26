#include <iostream>
using namespace std;

constexpr const int N = 33;
int a[N], f[N][N], rt[N][N];

void dfs(int L, int R) {
	if(L > R)
		return;
	int k = rt[L][R];
	cout << k << ' ';
	dfs(L, k - 1); dfs(k + 1, R);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i][i] = a[i]; rt[i][i] = i;
	}
	for(int len = 2; len <= n; ++len)
		for(int i = 1; i+len-1 <= n; ++i) {
			int j = i+len-1;
			for(int k = i; k <= j; ++k) {
				int L = k==i? 1: f[i][k-1], R = k==j? 1: f[k+1][j];
				int ans = L * R + a[k];
				if(ans > f[i][j]) {
					f[i][j] = ans;
					rt[i][j] = k;
				}
			}
		}
	cout << f[1][n] << '\n';
	dfs(1, n);
	cout << endl; return 0;
}
