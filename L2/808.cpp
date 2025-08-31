#include <bits/stdc++.h>
using namespace std;

int s[100003];
int t = 0;

int main()
{
	int n;
	scanf("%d", &n);
	int l = 0;
	while(n--)
	{
		int x;
		scanf("%d", &x);
		if(t > 0 && s[t] == x)
		{
			printf("pop\n");
			--t;
		}
		else
		{
			for(int i = l + 1; i <= x; ++i)
			{
				printf("push %d\n", i);
				s[++t] = i;
			}
			printf("pop\n");
			--t;
			l = x;
		}
	}
	return 0;
}