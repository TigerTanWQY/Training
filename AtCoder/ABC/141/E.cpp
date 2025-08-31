#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e3 + 3;
char s[N];
long long f[N][N];

int main() {
	int n;
	scanf("%d%s", &n, s + 1);
	long long ans = 0;
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(s[i] == s[j] && f[i - 1][j - 1] <= j - i - 1) {
				f[i][j] = f[i - 1][j - 1] + 1;
				ans = max(ans, f[i][j]);
			}
	printf("%lld\n", ans);
	return 0;
}
