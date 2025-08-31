#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
string s[1003], t;
int c[1003], top = 0;

int main()
{
	int n = 0;
	while(cin >> t)
		s[++n] = t;
	for(int i = 1; i <= n; ++i)
		if('0' <= s[i][0] && s[i][0] <= '9')
			c[++top] = stoi(s[i]);
		else
		{
			int x = c[top--], y = c[top--];
			if(s[i] == "+")
				c[++top] = (x + y) % MOD;
			else if(s[i] == "-")
				c[++top] = (y - x + MOD) % MOD;
			else/* if(s[i] == "*") */
				c[++top] = 1LL * x * y % MOD;
		}
	printf("%d", c[top]);
	return 0;
}