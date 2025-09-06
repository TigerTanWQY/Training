#include <bits/stdc++.h>
using namespace std;
#define max(a,b) (a>b?a:b)

constexpr const int N = 5e6 + 3;
int q[N * 2];
long long s[N], f[N], g[N];

int read() {
	int res = 0;
	char ch = getchar();
	for(; '0' > ch || ch > '9'; ch = getchar());
	for(; '0' <= ch && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

int main() {
	freopen("garden.in", "r", stdin);
	freopen("garden.out", "w", stdout);
	int n = read(), k = read();
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + read();
	int h = 1, t = 0;
	q[++t] = 0;
	for(int i = 1; i <= n; ++i) {
		int L = max(i - k, 0);
		for(; h <= t && q[h] < L; ++h);
		if(i >= 2) {
			for(; h <= t && g[q[t]] <= g[i - 1]; --t);
			q[++t] = i - 1;
		}
		f[i] = max(f[i - 1], s[i] + g[q[h]]);
		g[i] = f[i - 1] - s[i];
	}
	printf("%lld\n", f[n]);
	return 0;
}

