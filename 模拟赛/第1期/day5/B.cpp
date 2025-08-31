#include <cstdio>
using namespace std;

struct
{ int a, t, c, g; }
c[200003], chb[200003];

int main()
{
	int n, ans = 0;
	scanf("%d%*c", &n);
	for(int i = 1; i <= n; ++i)
	{
		char ch;
		scanf("%c", &ch);
		c[i].a = c[i - 1].a + 1;
		chb[i].t = chb[i - 1].t + 1;
		c[i].t = c[i - 1].t + 1;
		chb[i].a = chb[i - 1].a + 1;
		c[i].c = c[i - 1].c + 1;
		chb[i].g = chb[i - 1].g + 1;
		c[i].g = c[i - 1].g + 1;
		chb[i].c = chb[i - 1].c + 1;
		switch(ch)
		{
			case 'A':
				++c[i].a;
				++chb[i].t;
				break;
			case 'T':
				++c[i].t;
				++chb[i].a;
				break;
			case 'C':
				++c[i].c;
				++chb[i].g;
				break;
			case 'G':
				++c[i].g;
				++chb[i].c;
				break;
		}
	}
	for(int len = 2; len <= n; ++len)
		for(int l = 1; l <= n - len + 1; ++l)
		{
			int r = l + len - 1;
			if(c[r].a - c[l - 1].a == chb[r].a - chb[l - 1].a && c[r].t - c[l - 1].t == chb[r].t - chb[l - 1].t && c[r].c - c[l - 1].c == chb[r].c - chb[l - 1].c && c[r].g - c[l - 1].g == chb[r].g - chb[l - 1].g)
				++ans;
		}
	printf("%d", ans);
	return 0;
}