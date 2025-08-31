#include <cstdio>
#include <cstring>
using namespace std;

bool b[4004];
int n, k;

int main()
{
	memset(b, true, sizeof(b));
	scanf("%d%d", &n, &k);
	b[0] = false;
	while(k--)
	{
		int t, x;
		scanf("%d%d", &t, &x);
		b[x] = false;
		if(t == 1)
		{
			int y;
			scanf("%d", &y);
			b[y] = false;
		}
	}
	int l = 0, r = 0;
	for(int i = 1; i < n; i++)
		if(b[i])
		{
			if(b[i - 1])
			{
				b[i] = false;
				l--;
			}
			l++;
			r++;
		}
	printf("%d %d", l, r);
}