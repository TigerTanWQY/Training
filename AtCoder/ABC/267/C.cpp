#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 200003;
int a[N];
LL s[N], si[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i - 1];
	for(int i = 0; i < m; ++i)
		si[0] += (i + 1LL) * a[i];
	for(int i = 1; i <= n - m; ++i)
		si[i] = si[i - 1] + 1LL * m * a[i + m - 1] - (s[i + m - 1] - s[i - 1]);
	LL ans = -4e10 - 1;
	for(int i = 0; i <= n - m; ++i)
		ans = max(ans, si[i]);
	printf("%lld", ans);
	return 0;
}
