#include <cstdio>
#include <cstring>
using namespace std;
/* Ä£Äâ */
char s[10003], c[10003];

int main()
{
	int m;
	scanf("%s%d", s + 1, &m);
	while(m--)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		int len = r - l + 1;
		k %= len;
		for(int j = l; j <= r; ++j)
			if(j - k < l)
				c[j] = s[j - k + len];
			else
				c[j] = s[j - k];
		for(int j = l; j <= r; ++j)
			s[j] = c[j];
	}
	printf("%s", s + 1);
	return 0;
}