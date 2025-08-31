#include <cstdio>
using namespace std;

int f[1003], n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i / 2; ++j)
			f[i] += f[j];
		++f[i];
	}
	printf("%d", f[n]);
	return 0;
}