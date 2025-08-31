#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1000003;
const int LOGN = 23;
int f[2][LOGN][N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(f[1], -0x3f, sizeof(f[1]));
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		f[0][0][i] = x;
		f[1][0][i] = x;
	}
	for (int j = 1; j <= LOGN; ++j)
		for (int i = 1; i <= n - (1 << j) + 1; ++i)
			f[0][j][i] = max(f[0][j - 1][i], f[0][j - 1][i + (1 << (j - 1))]);
	for (int j = 1; j <= LOGN; ++j)
		for (int i = 1; i <= n - (1 << j) + 1; ++i)
			f[1][j][i] = min(f[1][j - 1][i], f[1][j - 1][i + (1 << (j - 1))]);
	for (int l, r, k; m--; ) {
		scanf("%d%d", &l, &r);
		k = log2(r - l + 1);
		printf("%d\n", max(f[0][k][l], f[0][k][r - (1 << k) + 1]) - min(f[1][k][l], f[1][k][r - (1 << k) + 1]));
	}
	return 0;
}
