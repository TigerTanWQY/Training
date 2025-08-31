#include <bits/stdc++.h>
using namespace std;

vector<int> a[1003];
int l = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		bool flag = true;
		for(int j = 1; j <= l; ++j)
			if(x < a[j].back())
			{
				a[j].push_back(x);
				flag = false;
				break;
			}
		if(flag)
			a[++l].push_back(x);
	}
	printf("%d\n", l);
	for(int i = 1; i <= l; ++i)
	{
		printf("%d:", i);
		for(const auto &x: a[i])
			printf("%d ", x);
		printf("\n");
	}
	return 0;
}