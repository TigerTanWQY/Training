#include <cstdio>
#include <cstring>
using namespace std;

char s[131];

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = n; i >= 1; --i)
		printf("%c", s[i]);
	return 0;
}