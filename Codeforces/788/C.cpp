#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 4'000'003;
int a[N], f[N];

int read() {
	int res = 0;
	char ch = getchar();
	for(; '0' > ch || ch > '9'; ch = getchar());
	for(; '0' <= ch && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

int main() {
	int n = read(), k = read();
	for(int i = 1; i <= k; ++i) {
		a[i] = read();
		a[i] -= n;
	}
	sort(a + 1, a + k + 1);
	const int m = unique(a + 1, a + k + 1) - a - 1;
	constexpr const int K = 500'003, V = 2'000'000;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= m; ++i) {
		f[V + a[i]] = 1;
		if(a[i] < 0)
			for(int j = K; j >= -K; --j)
				f[j + V] = min(f[j + V], f[j + V - a[i]] + 1);
		else
			for(int j = -K; j <= K; ++j)
				f[j + V] = min(f[j + V], f[j + V - a[i]] + 1);
	}
	if(f[V] == 0x3f3f3f3f)
		puts("-1");
	else
		printf("%d", f[V]);
	return 0;
}