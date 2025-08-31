#include <bits/stdc++.h>
using namespace std;

int solve(const int &n)
{
	if(n == 1)
		return 1;
	return solve(n - 1) * n;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", solve(n));
	return 0;
}