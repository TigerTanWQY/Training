#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
using PII = pair<int, int>;

const int N = 1000003;
PII a[N];
int c[N], r[N], d[N], len = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &r[i]);
	for(int i = 1; i <= n; ++i)
		a[c[i]].first = a[r[i]].second = i;
	sort(a + 1, a + n + 1, greater<PII>());
	d[++len] = a[1].second;
	for(int i = 2; i <= n; ++i)
	{
		int idx = lower_bound(d + 1, d + len + 1, a[i].second) - d;
		d[idx] = a[i].second;
		if(idx > len)
			++len;
	}
	printf("%d", len);
	return 0;
}