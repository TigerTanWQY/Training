#include <bits/stdc++.h>
using namespace std;

int n, c[15];
bool b1[15], b2[27], b3[27]; //b1为列, b2为斜线+，b3为斜线-（可能负）

void dfs(const int &i)
{
	if(i == n + 1)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d ", c[j]);
		printf("\n");
		return;
	}
	for(int j = 1; j <= n; ++j)
		if(!b1[j] && !b2[i + j] && !b3[i - j + n])
		{
			b1[j] = b2[i + j] = b3[i - j + n] = true;
			c[i] = j;
			dfs(i + 1);
			b1[j] = b2[i + j] = b3[i - j + n] = false;
		}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}