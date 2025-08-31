#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		char c;
		scanf("%*c%c", &c);
		printf("%d\n", c - '0');
	}
	return 0;
}