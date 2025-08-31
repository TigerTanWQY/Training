#include <bits/stdc++.h>
using namespace std;

char s[103];
int a[103];

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for(int i = 1; i <= len; ++i)
		a[i] = s[len - i + 1] - '0';
	for(int i = 1; i <= len; ++i)
		printf("%d", a[i]);
	return 0;
}