#include <bits/stdc++.h>
using namespace std;

bool b[1000003];
int c[1000003], len = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i)
	{
		if(!b[i])
			c[++len] = i;
		for(int j = 1; j <= len && i * c[j] <= n; ++j)
		{
			b[i * c[j]] = true;
			if(i % c[j] == 0)
				break;
		}
	}
	for(int i = 1; i <= len; ++i)
		printf("%d ", c[i]);
	return 0;
}