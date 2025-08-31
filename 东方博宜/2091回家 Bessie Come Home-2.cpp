#include <iostream>
#include <algorithm>
using namespace std;

int f[131][131];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i = 1; i <= 128; ++i)
		for(int j = 1; j <= 128; ++j)
			f[i][j] = 0x3f3f3f3f;
	int m;
	cin >> m;
	char maxn = 0;
	while(m--)
	{
		char x, y;
		int v;
		cin >> x >> y >> v;
		f[x][y] = f[y][x] = min(f[x][y], v);
		maxn = max(maxn, max(x, y));
	}
	for(int k = 1; k <= maxn; ++k)
		for(int i = 1; i <= maxn; ++i)
			for(int j = 1; j <= maxn; ++j)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	char ans = 'A';
	for(char i = 'B'; i <= 'Y'; ++i)
		if(f[i]['Z'] < f[ans]['Z'])
			ans = i;
	cout << ans << " " << f[ans]['Z'];
	return 0;
}