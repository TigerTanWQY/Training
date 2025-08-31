#include <cstdio>
#include <cstring>
using namespace std;

char s[13], t[1000003];

int main()
{
	scanf("%s", s);
	int n = strlen(s), m = 0, cnt = 0, pos = -1;
	for(char ch = getchar(); scanf("%c", &ch) != EOF && ch != '\n'; )
		t[m++] = ('A' <= ch && ch <= 'Z'? ch - 'A' + 'a': ch);
	for(int i = 0; i < n; ++i)
		if('A' <= s[i] && s[i] <= 'Z')
			s[i] += 'a' - 'A';
	for(int i = 0; i < m; ++i)
	{
		if(i + n - 1 >= m)
			break;
		bool match = true;
		for(int j = 0; j < n && match; ++j)
			if(t[i + j] != s[j])
				match = false;
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
	if(cnt)
		printf("%d %d", cnt, pos);
	else
		printf("-1");
	return 0;
}