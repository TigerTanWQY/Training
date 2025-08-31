#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int maxn = -1;
	while(n--)
	{
		char s[1003];
		scanf("%s", s);
		int score = 0;
		for(int i = 0; i < m; ++i)
			if(s[i] == '+')
				++score;
		maxn = max(maxn, score);
	}
	printf("%d", maxn);
	return 0;
}