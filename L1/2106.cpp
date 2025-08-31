#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x)
{
	if(x < 2)
		return false;
	for(int i = 2; i <= sqrt(x); ++i)
		if(x % i == 0)
			return false;
	return true;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = a; i <= b; ++i)
		if(is_prime(i))
			printf("%d\n", i);
	return 0;
}