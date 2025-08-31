#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	while(m--)
	{
		int opt, x;
		scanf("%d%d", &opt, &x);
		if(opt == 1)
		{
			int y;
			scanf("%d", &y);
			a.insert(a.begin() + x, y);
		}
		else/* if(opt == 2) */
			a.erase(a.begin() + x - 1);
	}
	for(const auto &p: a)
		printf("%d ", p);
	return 0;
}