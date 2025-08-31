#include <bits/stdc++.h>
using namespace std;

char s[100003];
int t = 0;

int main()
{
	int n;
	scanf("%d%*c", &n);
	for(int i = 1; i <= n; ++i)
	{
		char op;
		scanf("%c", &op);
		s[++t] = op;
		if(islower(s[t - 1]) && isupper(s[t]) && s[t] == toupper(s[t - 1]))
			t -= 2;
		else if(isupper(s[t - 1]) && islower(s[t]) && s[t] == tolower(s[t - 1]))
			t -= 2;
	}
	for(int i = 1; i <= t; ++i)
		printf("%c", s[i]);
	return 0;
}