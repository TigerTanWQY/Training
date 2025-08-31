#include <bits/stdc++.h>
using namespace std;

vector<int> a[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		char op[8];
		int x, y;
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'A')
			a[x].push_back(y);
		else/* if(op[0] == 'Q') */
		{
			if(y > a[x].size())
				printf("-1\n");
			else
				printf("%d\n", a[x][y - 1]);
		}
	}
	return 0;
}