#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for(int cnt = 1; cnt <= n; ++cnt)
		if(cnt % 2)
			for(int _ = 0; _ < n; ++_)
			{
				for(int __ = 0; __ <= _; ++__)
					printf("*");
				printf("\n");
			}
		else
			for(int k = 1; k <= n; ++k)
			{
				for(int _ = 1; _ <= n - k; ++_)
					printf(" ");
				for(int _ = 1; _ <= k; ++_)
					printf("*");
				printf("\n");
			}
	return 0;
}