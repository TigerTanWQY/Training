#include <bits/stdc++.h>
using namespace std;

char s1[13], s2[13];

int main()
{
	scanf("%s%s", s1 + 1, s2 + 1);
	int len = strlen(s2 + 1), flag = 0;
	while(strcmp(s1 + 1, s2 + 1) != 0 && flag++ < len)
	{
		char tmp = s1[1];
		for(int i = 2; i <= len; ++i)
			s1[i - 1] = s1[i];
		s1[len] = tmp;
	}
	if(flag >= len)
		printf("No");
	else
		printf("Yes");
	return 0;
}