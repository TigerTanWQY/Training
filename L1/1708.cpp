#include <bits/stdc++.h>
using namespace std;

char s[8];

int main()
{
	gets(s + 1);
	int len = strlen(s + 1);
	int cnt = 0;
	for(int i = 1; i <= len; ++i)
		if(s[i] != ' ')
			++cnt;
	cout << cnt;
	return 0;
}