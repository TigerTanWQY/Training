#include <cstdio>
using namespace std;

const char s[] = "NSWE";
const int d[][2]{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
const int N = 2003;
bool vis[N][N], G[N][N];
int a[N][N];

int main()
{
	int n, num = 1, num1 = 0;
	scanf("%d%*c", &n);
	vis[1000][1000] = true;
	a[1000][1000] = ++num;
	for(int x = 1000, y = 1000, tx = 1000, ty = 1000; n--; tx = x, ty = y)
	{
		char c = getchar();
		for(int i = 0; i < 4; ++i)
			if(c == s[i])
			{
				x += d[i][0];
				y += d[i][1];
				break;
			}
		if(!vis[x][y])
		{
			a[x][y] = ++num;
			vis[x][y] = true;
		}
		int last = a[tx][ty], now = a[x][y];
		if(!G[last][now])
		{
			G[last][now] = G[now][last] = true;
			++num1;
		}
	}
	printf("%d", num1 - num + 1);
	return 0;
}