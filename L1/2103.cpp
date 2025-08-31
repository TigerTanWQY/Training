#include <bits/stdc++.h>
using namespace std;

char s1[13], s2[13], s3[13];

int cnt(char s[], int len)
{
	int ret = 0;
	for(int i = 1; i <= len; ++i)
		if(s[i] == 'a')
			++ret;
	return ret;
}

int main()
{
	scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
	int l1 = strlen(s1 + 1), l2 = strlen(s2 + 1), l3 = strlen(s3 + 1);
	printf("%d\n%d\n%d", cnt(s1, l1), cnt(s2, l2), cnt(s3, l3));
	return 0;
}