#include <cstdio>
#include <cstring>
using namespace std;

char str[200003];

int main()
{
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for(int i = 1; i <= n; ++i)
		if(str[i] == 'P')
		{
			if(str[i + 1] == '?')
				str[i + 1] = 'D';
		}
		else if(str[i] == '?')
			str[i] = 'D';
	printf("%s", str + 1);
	return 0;
}