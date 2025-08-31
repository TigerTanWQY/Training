#include <bits/stdc++.h>
using namespace std;

bool check(const int &x)
{
	if(x < 2)
		return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		if(check(i))
			printf("%d ", i);
	return 0;
}