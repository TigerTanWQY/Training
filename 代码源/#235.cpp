#include <cstdio>
using namespace std;

int a[100003], b[100003];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		++b[a[i]];
	}
	for(int i = 1; i <= n; ++i)
		if(k - a[i] >= 0 && b[k - a[i]])
		{
			if(k - a[i] == a[i] && b[k - a[i]] <= 1)
				continue;
			printf("Yes");
			return 0;
		}
	printf("No");
	return 0;
}