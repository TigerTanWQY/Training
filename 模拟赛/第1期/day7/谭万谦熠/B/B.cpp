#include <cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int x, k, cnt = 0;
		scanf("%d%d", &x, &k);
		for(int i = x; i; i >>= 1)
			if(i % 2)
				++cnt;
		if(k <= x && k >= cnt)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}