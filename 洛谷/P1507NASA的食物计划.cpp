#include <cstdio>
#include <algorithm>
using namespace std;

int h[53], t[53], k[53], f[403][403];

int main()
{
	int H, T, n;
	scanf("%d%d%d", &H, &T, &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &h[i], &t[i], &k[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = H; j >= h[i]; --j)
			for(int l = T; l >= t[i]; --l)
				f[j][l] = max(f[j][l], f[j - h[i]][l - t[i]] + k[i]);
	printf("%d", f[H][T]);
	return 0;
}