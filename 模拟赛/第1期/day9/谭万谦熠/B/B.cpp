#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int N = 500003;
map<int, int> c;
long long s[N];

int main()
{
	int n, m;
	long long tot = 0LL;
	scanf("%d%d", &n, &m);
	for(int i = 1, x; i <= n; ++i)
	{
		scanf("%d", &x);
		tot += x - 1;
		++c[x];
	}
	for(int i = 1; i <= m; ++i)
		s[i] = s[i - 1] + max(0, c[i]);
	for(int i = 1; i <= m; ++i)
	{
		if(i != 1)
			tot += 2 * s[i - 1] - s[m];
		printf("%lld ", tot);
	}
	return 0;
}