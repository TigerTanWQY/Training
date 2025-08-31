#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[3003], w[3003][3003], f[3003][303], d[3003][303];

int main()
{
	int v, p;
	scanf("%d%d", &v, &p);
	for(int i = 1; i <= v; ++i)
		scanf("%d", &a[i]);
	for(int L = 1; L <= v; ++L)
	{
		w[L][L] = 0;
		for(int R = L + 1; R <= v; ++R)
			w[L][R] = w[L][R - 1] + a[R] - a[(L + R) >> 1];
	}
	sort(a + 1, a + v + 1);
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int R = 1; R <= p; ++R)
	{
		d[v + 1][R] = v;
		for(int L = v; L; --L)
		{
			int minx = 1 << 30, mini = 0;
			for(int k = d[L][R - 1]; k <= d[L + 1][R]; ++k)
				if(f[k][R - 1] + w[k + 1][L] < minx)
				{
					minx = f[k][R - 1] + w[k + 1][L];
					mini = k;
				}
			f[L][R] = minx;
			d[L][R] = mini;
		}
	}
	printf("%d", f[v][p]);
	return 0;
}