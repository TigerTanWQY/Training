#include <cstdio>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;
/* Ì°ÐÄ */
PII a[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + n + 1);
	PII x{a[1].second, 1};
	for(int i = 2; i <= n; ++i)
		if(a[i].second >= x.first)
			x = {a[i].second, x.second + 1};
	printf("%d", n - x.second);
	return 0;
}