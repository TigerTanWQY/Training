#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1003;
const int M = 2003;
pair<int, int> a[N], b[N];
bool G[M][M];
char sa[N], sb[N];

int main()
{
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	for(int i = 1; i <= n1; ++i)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		G[a[i].first][a[i].second] = true;
	}
	for(int i = 1; i <= n2; ++i)
	{
		scanf("%d%d", &b[i].first, &b[i].second);
		G[b[i].first][b[i].second] = true;
	}
	for(int i = 1; i <= n1; ++i)
		sa[i] = '0';
	for(int i = 1; i <= n2; ++i)
		sb[i] = '0';
	for(int i = 1; i <= n1; ++i)
		for(int j = 1; j <= n2; ++j)
		{
			if(a[i].first == b[j].first)
			{
				bool flag = true;
				for(int k = min(a[i].second, b[j].second) + 1; k < max(a[i].second, b[j].second) && flag; ++k)
					if(G[a[i].first][k])
						flag = false;
				if(flag)
					sa[i] = sb[j] = '1';
			}
			if(a[i].second == b[j].second)
			{
				bool flag = true;
				for(int k = min(a[i].first, b[j].first) + 1; k < max(a[i].first, b[j].first) && flag; ++k)
					if(G[k][a[i].second])
						flag = false;
				if(flag)
					sa[i] = sb[j] = '1';
			}
		}
	printf("%s\n%s", sa + 1, sb + 1);
	return 0;
}