#include <iostream>
#include <cstring>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

constexpr const int N = 103;
mint f[N][N][N];
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	mint ans = 0;
	for(int i = 1; i <= n; ++i) {
		memset(f, 0, sizeof(f));
		f[0][0][0] = 1;
		for(int j = 0; j < n; ++j)
			for(int k = 0; k <= i; ++k)
				for(int l = 0; l < i; ++l) {
					f[j + 1][k][l] += f[j][k][l];
					if(k != i)
						f[j + 1][k + 1][(l + a[j]) % i] += f[j][k][l];
				}
		ans += f[n][i][0];
	}
	cout << ans.val() << endl;
	return 0;
}