#include <cstdio>
#include <algorithm>
using namespace std;

int a[200003];

int main()
{
	int n, L, R;
	scanf("%d%d%d", &n, &L, &R);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
		printf("%d ", min(max(L, a[i]), R));
	return 0;
}