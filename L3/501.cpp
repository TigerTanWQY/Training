#include <bits/stdc++.h>
using namespace std;

long long f[53];

long long solve(const int &n)
{
	if(f[n])
		return f[n];
	if(n <= 1)
		return 1;
	return f[n] = solve(n - 1) + solve(n - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld", solve(n));
	return 0;
}