#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
	int h, a, c;
	bool operator<(const Node &A) const
	{ return a < A.a; }
} a[403];
bool f[40003]{true};

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i].h, &a[i].a, &a[i].c);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= a[i].c; ++j)
			for(int k = a[i].a; k >= a[i].h; --k)
				f[k] |= f[k - a[i].h];
	for(int j = a[n].a; j >= 0; --j)
		if(f[j])
		{
			printf("%d", j);
			break;
		}
	return 0;
}