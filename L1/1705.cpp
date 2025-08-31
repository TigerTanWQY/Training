#include <bits/stdc++.h>
using namespace std;

char s[103];

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int ans = 0;
	for(register auto i = 1; i <= len; ++i)
		if(s[i] == 'a')
			++ans;
	printf("%d", ans);
	return 0;
}