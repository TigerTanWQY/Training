#include <cstdio>
#include <cstring>
using namespace std;

char s[1003];

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if(n % 2 == 0)
	{
		printf("No");
		return 0;
	}
	for(int i = 2; i <= n; i += 2)
		if(!((s[i] == '#' && s[i + 1] == '#') || (s[i] != '#' && s[i + 1] != '#')))
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}