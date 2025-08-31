#include <bits/stdc++.h>
using namespace std;

char s[103];
int a[153];

int main()
{
	int n;
	scanf("%s%d", s + 1, &n);
	int la = strlen(s + 1);
	for(int i = 1; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	while(n--)
	{
		int x;
		cin >> x;
		if(x == 0)
		{
			printf("0");
			return 0;
		}
		for(int i = 1; i <= la; ++i)
			a[i] *= x;
		for(int i = 1; i <= la; ++i)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		while(a[la + 1] > 0)
		{
			++la;
			a[la + 1] = a[la] / 10;
			a[la] %= 10;
		}
	}
	while(a[la] == 0 && la > 1)
		--la;
	for(int i = la; i >= 1; --i)
		printf("%d", a[i]);
	return 0;
}