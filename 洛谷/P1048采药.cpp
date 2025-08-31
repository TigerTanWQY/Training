#include <cstdio>
#include <algorithm>
using namespace std;

int v[103], w[103], f[1003];

int main()
{
	int T, M;
	scanf("%d%d", &T, &M);
	for(int i = 1; i <= M; ++i)
		scanf("%d%d", &v[i], &w[i]);
	for(int i = 1; i <= M; ++i)
		for(int j = T; j >= v[i]; --j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d", f[T]);
	return 0;
}