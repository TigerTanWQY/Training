#include <bits/stdc++.h>
using namespace std;

pair<int, int> q[103];
int f = 1, r = 0;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int opt;
		scanf("%d", &opt);
		if(opt == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			q[++r] = make_pair(x, y);
		}
		else
			if(r - f + 1 <= 0)
				printf("error\n");
			else
			{
				printf("%d %d\n", q[f].first, q[f].second);
				++f;
			}
	}
	return 0;
}