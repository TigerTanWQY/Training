#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int st[N], tp[N][N], de[N], tt[N];
bool is[N], bo[N];

int main()
{
	int n, m, top = 0, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		memset(is, false, sizeof(is));
		int s;
		scanf("%d", &s);
		for(int j = 1; j <= s; ++j)
		{
			scanf("%d", &st[j]);
			is[st[j]] = true;
		}
		for(int j = st[1]; j <= st[s]; ++j)
			if(!is[j])
				for(int k = 1; k <= s; ++k)
					if(!tp[j][st[k]])
					{
						tp[j][st[k]] = 1;
						++de[st[k]];
					}
	}
	do
	{
		top = 0;
		for(int i = 1; i <= n; ++i)
			if(de[i] == 0 && !bo[i])
			{
				tt[++top] = i;
				bo[i] = true;
			}
		for(int i = 1; i <= top; ++i)
			for(int j = 1; j <= n; ++j)
				if(tp[tt[i]][j])
				{
					tp[tt[i]][j] = 0;
					--de[j];
				}
		++ans;
	} while(top);
	printf("%d", ans - 1);
	return 0;
}