#include <cstdio>
using namespace std;

int pre[1027], mid[1027];

void dfs(const int &L1, const int &R1, const int &L2, const int &R2)
{
	if(L1 >= R1)
	{
		if(L1 == R1)
			printf("%d ", pre[L1]);
		return;
	}
	int x;
	for(int i = L2; i <= R2; ++i)
		if(mid[i] == pre[L1])
		{
			x = i;
			break;
		}
	dfs(L1 + 1, L1 + x - L2, L2, x - 1);
	dfs(L1 + x - L2 + 1, R1, x + 1, R2);
	printf("%d ", pre[L1]);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &pre[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &mid[i]);
	dfs(1, n, 1, n);
	return 0;
}