#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int _ = 0; _ < n; ++_)
		a.push_back(0);
	for(int _ = 0; _ < m - n; ++_)
		a.push_back(1);
	do
	{
		for(int i = 0; i < m; ++i)
			if(a[i] == 0)
				printf("%d ", i + 1);
		printf("\n");
	} while(next_permutation(a.begin(), a.end()));
	return 0;
}