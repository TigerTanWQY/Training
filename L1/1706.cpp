#include <bits/stdc++.h>
using namespace std;

char s[103];

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for(int i = 1; i <= len / 2; ++i)
		swap(s[i], s[len - i + 1]);
	printf("%s", s + 1);
	return 0;
}