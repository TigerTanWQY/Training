#include <iostream>
using namespace std;
using ll = long long;

const ll inf = 1e18;
const ll di[2] = {1, 0}, dj[2] = {0, 1};
char a[2005][2005];
ll h, w, r[2005], c[2005], dp[2005][2005][2][2];

ll solve()
{
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			for(int d = 0; d < 2; d++)
				for(int f = 0; f < 2; f++)
					dp[i][j][d][f] = inf;
	for(int r1 = 0; r1 < 2; r1++)
	{
		int c1 = (a[1][1]^r1);
		dp[1][1][0][c1] = r1*r[1] + c1*c[1];
		dp[1][1][1][r1] = r1*r[1] + c1*c[1];
	}
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			for(int d = 0; d < 2; d++)
				for(int l = 0; l < 2; l++)
				{
					int ni = i + di[d], nj = j + dj[d];
					if(ni > h || nj > w)
						continue;
					int flip = a[ni][nj]^l, cost = 0;
					if(d == 0)
						cost = r[ni]*flip;
					else
						cost = c[nj]*flip;
					for(int nd = 0; nd < 2; nd++)
					{
						int nl = l;
						if(d != nd)
							nl = flip;
						dp[ni][nj][nd][nl] = min(dp[ni][nj][nd][nl], dp[i][j][d][l] + cost);
					}
				}
	ll ret = inf;
	for(int d = 0; d < 2; d++)
		for(int f = 0; f < 2; f++)
			ret = min(ret, dp[h][w][d][f]);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> h >> w;
	for(int i = 1; i <= h; i++)
		cin >> r[i];
	for(int i = 1; i <= w; i++)
		cin >> c[i];
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
		{
			cin >> a[i][j];
			a[i][j] -= '0';
		}
	ll ans = solve();
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			a[i][j] ^= 1;
	ans = min(ans, solve());
	cout << ans;
	return 0;
}