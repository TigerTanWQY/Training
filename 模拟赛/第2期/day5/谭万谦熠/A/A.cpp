#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

int a[103], n, k;

inline bool check()
{
	for(int i = 1; i <= n; ++i)
		if(a[i] < k)
			return true;
	return false;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	while(check())
	{
		list<int> l;
		bool flag = false;
		for(int i = 1; i <= n; ++i)
			if(a[i] != a[i - 1] && a[i] < k)
			{
				l.push_back(i);
				flag = true;
			}
		if(flag)
		{
			++ans;
			for(const auto &p: l)
				++a[p];
			sort(a + 1, a + n + 1);
		}
	}
	printf("%d", ans);
	return 0;
}