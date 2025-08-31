#include <bits/stdc++.h>
using namespace std;

int a[100003], n, A, R, M;

inline long long f(const int &x)
{
	long long y = 0, z = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] <= x)
			y += x - a[i];
		else
			z += a[i] - x;
	long long res = min(y, z) * M;
	if(y > z)
		res += (y - z) * A;
	else
		res += (z - y) * R;
	return res;
}

int main()
{
	scanf("%d%d%d%d", &n, &A, &R, &M);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	M = min(M, A + R);
	int l = 0, r = 1e9;
	while(l + 2 < r)
	{
		int M1 = l + (r - l) / 3, M2 = l + (r - l) / 3 * 2;
		if(f(M1) > f(M2))
			l = M1;
		else
			r = M2;
	}
	long long ans = f(l);
	for(int i = l + 1; i <= r; ++i)
		ans = min(ans, f(i));
	printf("%lld", ans);
	return 0;
}