#include <cstdio>
#include <algorithm>
using namespace std;

int x[100003], f[100003];

int main()
{
	int n, A, B, C;
	scanf("%d%d%d%d", &n, &A, &B, &C);
	for(int i = 1; i <= n; ++i)
		x[i] = ((long long)A * i * i + B * i + C) % 20000 - 10000;
	f[1] = x[1];
	for(int i = 2; i <= n + 1; ++i)
		f[i] = x[i] + max(f[i - 2], f[i - 1]);
	printf("%d", f[n + 1]);
	return 0;
}