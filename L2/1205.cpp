#include <bits/stdc++.h>
using namespace std;

char s[13], t[1000003];

int main(){
	scanf("%s", s);
	int n = strlen(s), m = 0;
	char ch;
	scanf("%c", &ch);
	while(scanf("%c", &ch) == 1 && ch != '\n')
		t[m++] = ch;
	for(int i = 0; i < n; ++i)
		if('A' <= s[i] && s[i] <= 'Z')
			s[i] += 'a' - 'A';
	for(int i = 0; i < m; ++i)
		if('A' <= t[i] && t[i] <= 'Z')
			t[i] += 'a' - 'A';
	int cnt = 0, pos = -1;
	for(int i = 0; i < m; ++i)
	{
		if(i + n - 1 >= m)
			break;
		bool match = true;
		for(int j = 0; j < n; ++j)
			if(t[i + j] != s[j])
			{
				match = false;
				break;
			}
		if(i != 0 && t[i - 1] != ' ')
			match = false;
		if(i + n < m && t[i + n] != ' ')
			match = false;
		if(match)
		{
			++cnt;
			if(pos == -1)
				pos = i;
		}
	}
	if(cnt == 0)
		printf("-1");
	else
		printf("%d %d", cnt, pos);
	return 0;
}