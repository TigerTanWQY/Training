#include <bits/stdc++.h>
using namespace std;

char s[103];

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int cnta = 0, cntb = 0, cntc = 0;
	for(int i = 1; i <= len; ++i)
		if(s[i] == 'a')
			++cnta;
		else if(s[i] == 'b')
			++cntb;
		else if(s[i] == 'c')
			++cntc;
	printf("%d", max(cnta, max(cntb, cntc)));
	return 0;
}