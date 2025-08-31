#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 1'003;
int a[N];
long long f[N][N];

int read() {
	int res = 0;
	char ch = getchar();
	for(; '0' > ch || ch > '9'; ch = getchar());
	for(; '0' <= ch && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

int main() {
	int _T = read();
	for(int n, V, m; _T--; ) {
		n = read(); V = read(); m = read();
		for(int i = 1; i <= n; ++i)
			a[i] = read();
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; ++i)
			for(int k = m; k; --k)
				for(int j = V; j >= a[i]; --j)
					f[k][j] = max({f[k][j], f[k - 1][V] + 1, f[k][j - a[i]] + 1});
		printf("%lld\n", f[m][V]);
		if(_T)
			putchar('\n');
	}
	return 0;
}