#include <cstdio>
#include <cstring>
using namespace std;

char s[200003], t[200003];

int main()
{
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 1, j = 1; i <= n && j <= m; ++i)
		if(s[i] == t[j])
			++j;
		else if(t[j] == s[i - 1])
			while(t[j] == s[i])
				++j;
		else
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}