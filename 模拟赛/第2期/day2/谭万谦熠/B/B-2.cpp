#include <cstdio>
#include <algorithm>
using namespace std;
/* ±©Á¦ 50 ·Ö */
pair<int, int> a[100003];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	for(int i = 1; i <= n; ++i)
	{
		bool flag = false;
		for(int j = 1; j <= n && !flag; ++j)
			if(a[j].first < a[i].first && a[j].second > a[i].second)
				flag = true;
		ans += flag;
	}
	printf("%d", ans);
	return 0;
}