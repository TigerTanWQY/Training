#include <iostream>
#include <atcoder/modint>
using std::cin;

atcoder::modint1000000007 f[103][100'003];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	f[0][0] = 1;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		f[i][0] = 1;
		for(int j = 1; j <= k; ++j) {
			f[i][j] = f[i - 1][j] + f[i][j - 1];
			if(j - x >= 1)
				f[i][j] -= f[i - 1][j - x - 1];
		}
	}
	std::cout << f[n][k].val() << std::endl;
	return 0;
}