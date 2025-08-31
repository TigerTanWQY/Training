#include <cstdio>
using namespace std;

char a[1003][1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		{
			if(i + 5 < n)
			{
				int cnt = 0;
				for(int k = 0; k < 6; ++k)
					if(a[i + k][j] == '#')
						++cnt;
				if(cnt >= 4)
				{
					printf("Yes");
					return 0;
				}
			}
			if(j + 5 < n)
			{
				int cnt = 0;
				for(int k = 0; k < 6; ++k)
					if(a[i][j + k] == '#')
						++cnt;
				if(cnt >= 4)
				{
					printf("Yes");
					return 0;
				}
			}
			if(i + 5 < n && j + 5 < n)
			{
				int cnt = 0;
				for(int k = 0; k < 6; ++k)
					if(a[i + k][j + k] == '#')
						++cnt;
				if(cnt >= 4)
				{
					printf("Yes");
					return 0;
				}
			}
			if(0 <= i - 5 && j + 5 < n)
			{
				int cnt = 0;
				for(int k = 0; k < 6; ++k)
					if(a[i - k][j + k] == '#')
						++cnt;
				if(cnt >= 4)
				{
					printf("Yes");
					return 0;
				}
			}
		}
	printf("No");
	return 0;
}