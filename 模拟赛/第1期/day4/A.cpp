#include <cstdio>
using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	long long a = 1;
	for(int i = 0; i <= 38; ++i)
	{
		int b = 1;
		for(int j = 0; j <= 26; ++j)
		{
			if(a + b == n)
			{
				printf("%d %d", i, j);
				return 0;
			}
			b *= 5;
		}
		a *= 3;
	}
	printf("-1");
	return 0;
}