#include <cstdio>
using namespace std;

int a[1000003];

int main()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	int n, X, ans = 0;
	scanf("%d%d", &n, &X);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i != j && (a[i] ^ a[j]) == X)
				++ans;
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
