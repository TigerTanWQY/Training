#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int f[100003], c[100003], len = 0;
bool b[100003];

void work(int n, const int &s)
{
	for(int i = 1; i <= len && c[i] * c[i] <= n; ++i)
		for(; n % c[i] == 0; n /= c[i])
			f[c[i]] += s;
	if(n != 1)
		f[n] += s;
}

int main()
{
	for(int i = 2; i <= 100000; ++i)
	{
		if(!b[i])
			c[++len] = i;
		for(int j = 1; j <= len && i * c[j] <= 100000; ++j)
		{
			b[i * c[j]] = true;
			if(i % c[j] == 0)
				break;
		}
	}
	int n, m;
	scanf("%d%d", &n, &m);
	if(m > n)
	{
		printf("0");
		return 0;
	}
	for(int i = n - m + 1; i <= n; ++i)
		work(i, 1);
	for(int i = 2; i <= m; ++i)
		work(i, -1);
	long long ans = 1;
	for(int i = 2; i <= 100000; ++i)
		while(f[i]--)
			ans = ans * i % MOD;
	printf("%lld", ans);
	return 0;
}