#include <bits/stdc++.h>
using namespace std;

struct Data
{
	int v, i;
	inline bool operator<(const Data &A) const
	{
		if(v != A.v)
			return v < A.v;
		return i < A.i;
	}
} a[100003], b[100003], c[100003];
int q[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].v);
		a[i].i = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		q[a[i].i] = i;
	for(int i = 1; i <= n; ++i)
		printf("%d ", q[i]);
	return 0;
}