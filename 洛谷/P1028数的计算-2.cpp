#include <cstdio>
using namespace std;

int f[1003], n;

int dfs(const int &p)
{
	if(p < 1)
		return 0;
	if(f[p])
		return f[p];
	f[p] = 1;
	for(int i = 1; i <= p / 2; ++i)
		f[p] += dfs(i);
	return f[p];
}

int main()
{
	scanf("%d", &n);
	dfs(n);
	printf("%d", f[n]);
	return 0;
}