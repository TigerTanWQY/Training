#include <cstdio>
#include <cstring>
using namespace std;

char s[100003], t[100003];

int main()
{
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1), flag = (s[1] - t[1] + 26) % 26;
	for(int i = 2; i <= n; ++i)
		if((s[i] - t[i] + 26) % 26 != flag)
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}