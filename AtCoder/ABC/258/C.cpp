#include <cstdio>
using namespace std;

char s[500005];

int main()
{
	int n, q, p = 0;
	scanf("%d%d%s", &n, &q, s);
	while(q--)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if(op == 1)
			p = (p + x) % n;
		else
		{
			putchar(s[(x - p - 1 + n) % n]);
			putchar('\n');
		}
	}
	return 0;
}