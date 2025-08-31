#include <cstdio>
using namespace std;

int a[1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	printf("0 1 ");
	for(int i = 3; i <= n; ++i)
	{
		int ans = 0, j = i - 1;
		for(; j >= 1 && a[j] < a[i]; --j)
			++ans;
		if(j)
			++ans;
		printf("%d ", ans);
	}
	return 0;
}