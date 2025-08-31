#include <cstdio>
#include <cstring>
using namespace std;

char op[6];
int a[103][103];

int main()
{
	int n, m, cnt = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	while(true)
	{
		scanf("%s", op);
		if(strcmp(op, "end") == 0)
			break;
		if(op[0] == 'l')
			++cnt;
		else
			--cnt;
	}
	switch(cnt % 4)
	{
		case 0:
			for(int i = 1; i <= n; ++i)
			{
				for(int j = 1; j <= m; ++j)
					printf("%d ", a[i][j]);
				printf("\n");
			}
			break;
		case -3:
		case 1:
			for(int j = m; j >= 1; --j)
			{
				for(int i = 1; i <= n; ++i)
					printf("%d ", a[i][j]);
				printf("\n");
			}
			break;
		case -2:
		case 2:
			for(int i = n; i >= 1; --i)
			{
				for(int j = m; j >= 1; --j)
					printf("%d ", a[i][j]);
				printf("\n");
			}
			break;
		case -1:
		case 3:
			for(int j = 1; j <= m; ++j)
			{
				for(int i = n; i >= 1; --i)
					printf("%d ", a[i][j]);
				printf("\n");
			}
			break;
	}
	return 0;
}