#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
bool b[303];
int f[303][303], v[303], ans[303];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &f[i][j]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	for(int l = n; l; --l)
	{
		int k = v[l];
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[i][k] + f[k][j];
		b[k] = true;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(b[i] && b[j])
					ans[l] += f[i][j];
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}