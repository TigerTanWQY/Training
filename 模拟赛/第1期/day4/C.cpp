#include <cstdio>
using namespace std;

struct Data
{
	char op;
	int x;
	bool type;
} a[1000003];
bool b[2][1000003];

int main()
{
	int n, m, q;
	long long ans = 0;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= q; ++i)
		scanf("%*c%c%d%d", &a[i].op, &a[i].x, &a[i].type);
	int r = n, c = m;
	for(int i = q; i >= 1; --i)
		if(a[i].op == 'r')
		{
			if(!b[0][a[i].x])
			{
				if(a[i].type)
					ans += c;
				b[0][a[i].x] = true;
				--r;
			}
		}
		else
			if(!b[1][a[i].x])
			{
				if(a[i].type)
					ans += r;
				b[1][a[i].x] = true;
				--c;
			}
	printf("%lld", ans);
	return 0;
}