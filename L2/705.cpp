#include <bits/stdc++.h>
using namespace std;

int k[100003], b[100003];
int n;

long long calc(int x)
{
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		if(b[i] <= x)
			ans += (x - b[i]) / k[i] + 1;
	return ans;
}

int main()
{
	int m;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &k[i], &b[i]);
	scanf("%d", &m);
	int L = 0, R = 100000000;
	while(L + 1 < R)
	{
		int M = (L + R) >> 1;
		if(calc(M) < m)
			L = M;
		else
			R = M;
	}
	printf("%d", R);
	return 0;
}