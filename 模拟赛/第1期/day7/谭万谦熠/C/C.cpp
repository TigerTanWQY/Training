#include <cstdio>
using namespace std;

char str[1000003];
int c[1000003];

int main()
{
	int n, k, tot = 0;
	scanf("%d%d%s", &n, &k, str + 1);
	for(int i = 1; i <= n; ++i)
	{
		tot += c[i];
		if(tot % 2)
			if(str[i] == '0')
				str[i] = '1';
			else
				str[i] = '0';
		if(str[i] == '1' && i + k <= n + 1)
		{
			str[i] = '0';
			++c[i + 1];
			--c[i + k];
		}
	}
	printf("%s", str + 1);
	return 0;
}