#include <bits/stdc++.h>
using namespace std;

int n, c[17];
bool b[17], prime[30];

void dfs(const int &i)
{
	if(i == n + 1)
	{
		if(!prime[c[i - 1] + c[1]])
			return;
		for(int j = 1; j <= n; ++j)
			printf("%d ", c[j]);
		printf("\n");
		return;
	}
	for(int j = 1; j <= n; ++j)
		if(!b[j] && (prime[j + c[i - 1]] || i == 1))
		{
			c[i] = j;
			b[j] = true;
			dfs(i + 1);
			b[j] = false;
		}
}

int main()
{
	scanf("%d", &n);
	for(int i = 2; i < 2 * n; ++i)
	{
		prime[i] = true;
		for(int j = 2; j * j <= i; ++j)
			if(i % j == 0)
			{
				prime[i] = false;
				break;
			}
	}
	dfs(1);
	return 0;
}