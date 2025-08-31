#include <cstdio>
#include <cstring>
using namespace std;

struct Data
{ int k[8], f[8], v, cnt; }
a[8];
int cnt[363];

int main()
{
	for(int i = 1; i <= 5; ++i)
	{
		scanf("%d%d", &a[i].v, &a[i].cnt);
		for(int j = 1; j <= a[i].cnt; ++j)
			scanf("%d%d", &a[i].f[j], &a[i].k[j]);
	}
	for(int i = 0; i < 360; ++i)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int j = 1; j <= 5; ++j)
			for(int k = 1; k <= a[j].cnt; ++k)
				for(int w = 0; w <= a[j].k[k]; ++w)
					++cnt[(a[j].f[k] + i * a[j].v + 360 + w) % 360];
		for(int j = 0; j < 360; ++j)
			if(cnt[j] == 5)
			{
				printf("%d", i);
				return 0;
			}
	}
	printf("none");
	return 0;
}