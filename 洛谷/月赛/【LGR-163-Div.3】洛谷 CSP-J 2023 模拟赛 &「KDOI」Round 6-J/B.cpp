#include <cstdio>
#include <algorithm>
using namespace std;

int a[200003], ovt[200003], rvs[200003];

int main()
{
	int n;
	scanf("%d", &n);
	bool flag = true;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if(a[i])
			flag = false;
	}
	if(flag)
	{
		for(int i = 1; i <= n / 2 + !!(n % 2); ++i)
			printf("1 ");
		for(int i = 1; i <= n / 2; ++i)
			printf("0 ");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
	{
//		for(int j = 1, k = i; j < k; ++j, --k)
//			swap(a[j], a[k]);
//		for(int j = 1; j <= i; ++j)
//			a[j] = !a[j];
		++ovt[1];
		--ovt[i + 1];
		++rvs[1];
		--rvs[i + 1];
	}
	for(int i = 1; i <= n; ++i)
	{
		ovt[i] += ovt[i - 1];
		rvs[i] += rvs[i - 1];
	}
	for(int i = 1; i <= n; ++i)
	{
		ovt[i] %= 2;
		rvs[i] %= 2;
	}
	for(int i = 1, j = 1; i <= n && j <= n; ++i)
	{
		if(ovt[i])
		{
			swap(a[i], a[j]);
			j = i + 1;
		}
		if(rvs[i])
			a[i] = !a[i];
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}