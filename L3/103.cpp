#include <bits/stdc++.h>
using namespace std;

int solve(const int &n)
{
	if(n <= 1)
		return 0;
	return n + solve(n / 2) + solve(n - n / 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", solve(n));
	return 0;
}