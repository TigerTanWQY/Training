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
		int x, y;
		scanf("%d%d", &x, &y);
		reverse(a.begin() + x - 1, a.begin() + y);
	}
	for(const auto &p: a)
		printf("%d ", p);
	return 0;
}