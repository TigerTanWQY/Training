#include <iostream>
#include <cstring>
using namespace std;

constexpr const int P = 998244353, N = 103;
int a[N], f[N][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		memset(f, 0, sizeof(f));
		f[0][0][0] = 1;
		for(int j = 0; j < n; ++j)
			for(int k = 0; k <= i; ++k)
				for(int l = 0; l < i; ++l) {
					f[j + 1][k][l] += f[j][k][l];
					f[j + 1][k][l] %= P;
					if(k != i) {
						f[j + 1][k + 1][(l + a[j]) % i] += f[j][k][l];
						f[j + 1][k + 1][(l + a[j]) % i] %= P;
					}
				}
		ans += f[n][i][0];
		ans %= P;
	}
	cout << ans << endl;
	return 0;
}