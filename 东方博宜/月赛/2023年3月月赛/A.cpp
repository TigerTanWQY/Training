#include <bits/stdc++.h>
using namespace std;

char s[63];

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", s);
		int x = s[strlen(s) - 1] - '0';
		if(x % 2 == 1)
			printf("odd\n");
		else
			printf("even\n");
	}
	return 0;
}