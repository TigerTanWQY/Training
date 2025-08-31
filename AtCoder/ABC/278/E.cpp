#include <iostream>
using namespace std;

int a[303][303], f[303][303][303];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int H, W, N, h, w;
	cin >> H >> W >> N >> h >> w;
	for(int i = 1; i <= H; ++i)
		for(int j = 1; j <= W; ++j)
		{
			cin >> a[i][j];
			for(int k = 1; k <= N; ++k)
				f[i][j][k] = f[i - 1][j][k] + f[i][j - 1][k] - f[i - 1][j - 1][k] + (k == a[i][j]);
		}
	for(int i = h; i <= H; ++i)
	{
		for(int j = w; j <= W; ++j)
		{
			int cnt = 0;
			for(int k = 1; k <= N; ++k)
				if(f[H][W][k] - (f[i][j][k] - f[i - h][j][k] - f[i][j - w][k] + f[i - h][j - w][k]) > 0)
					cnt++;
			cout << cnt << ' ';
		}
		cout << '\n';
	}
	return 0;
}