#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int c;
		scanf("%d", &c);
		vector<int> v;
		while(c--)
		{
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		a.push_back(v);
	}
	sort(a.begin(), a.end());
	for(const auto &p: a)
	{
		for(const auto &q: p)
			printf("%d ", q);
		printf("\n");
	}
	return 0;
}