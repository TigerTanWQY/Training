#include <cstdio>
#include <algorithm>
using namespace std;

int t[103], f1[103], f2[103];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	for(int i = 1; i <= n; ++i)
	{
		f1[i] = 1;
		for(int j = 1; j < i; ++j)
			if(t[j] < t[i])
				f1[i] = max(f1[i], f1[j] + 1);
	}
	for(int i = n; i >= 1; --i)
	{
		f2[i] = 1;
		for(int j = n; j > i; --j)
			if(t[j] < t[i])
				f2[i] = max(f2[i], f2[j] + 1);
	}
	for(int i = 1; i <= n; ++i)
		ans = max(ans, f1[i] + f2[i] - 1);
	printf("%d", n - ans);
	return 0;
}