#include <cstdio>
using namespace std;

const int N = 1000000;
int c[N + 3];
long long ans[N + 3];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int l, r; n--; ++c[l], --c[r + 1])
		scanf("%d%d", &l, &r);
	for(int i = 1; i <= N; ++i)
		c[i] += c[i - 1];
	for(int i = 1; i <= N; ++i)
		for(int j = i; j <= N; j += i)
			ans[i] += c[j];
	for(int x; q--; printf("%lld\n", ans[x]))
		scanf("%d", &x);
	return 0;
}