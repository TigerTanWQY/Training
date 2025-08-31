#include <bits/stdc++.h>
using namespace std;

char str[30], l, r;
int w;

bool getnext(char *s)
{
	bool flag = false;
	for(int i = w - 1; i >= 0; --i)
		if(s[i] + 1 <= r && w - i <= r - s[i])
		{
			++s[i];
			for(int j = i + 1; j < w; ++j)
				s[j] = s[j - 1] + 1;
			flag = true;
			break;
		}
	return flag;
}

int main()
{
	int s, t;
	scanf("%d%d%d%s", &s, &t, &w, str);
	l = 'a' + s - 1;
	r = 'a' + t - 1;
	for(int i = 0; i < 5 && getnext(str); ++i)
		printf("%s\n", str);
	return 0;
}