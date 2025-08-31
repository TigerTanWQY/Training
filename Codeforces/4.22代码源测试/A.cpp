#include <bits/stdc++.h>
using namespace std;

char s[43][10];
int len[43];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; ++i)
		{
			scanf("%s", s[i] + 1);
			len[i] = strlen(s[i] + 1);
		}
		if((s[n][len[n]] != '3' && s[n][len[n]] != '4') || (s[2 * n][len[2 * n]] != '1' && s[2 * n][len[2 * n]] != '2'))
		{
			printf("NO\n");
			continue;
		}
		bool flag = true;
		for(int i = 1; i <= n; ++i)
		{
			if(s[i][len[i]] == '1' || s[i][len[i]] == '2')
			{
				if(!(s[i + n][len[i + n]] == '3' || s[i + n][len[i + n]] == '4'))
				{
					printf("NO\n");
					flag = false;
					break;
				}
			}
			else if(s[i][len[i]] == '3' || s[i][len[i]] == '4')
				if(!(s[i + n][len[i + n]] == '1' || s[i + n][len[i + n]] == '2'))
				{
					printf("NO\n");
					flag = false;
					break;
				}
		}
		if(flag)
			printf("YES\n");
	}
	return 0;
}