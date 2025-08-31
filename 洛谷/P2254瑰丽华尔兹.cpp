#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

const int dxy[2][5]{{0, -1, 1, 0, 0}, {0, 0, 0, -1, 1}};
const int N = 203;
struct Node
{ int v, pos; };
char a[N][N];
int f[N][N], ans = 0;

void DP(int x, int y, const int& L, const int& tim, const int& d) {
	deque<Node> q;
	for(int i = 1; i <= L; ++i, x += dxy[0][d], y += dxy[1][d])
		if(a[x][y] == 'x')
			q.clear();
		else {
			while(!q.empty() && q.back().v + i - q.back().pos <= f[x][y])
				q.pop_back();
			q.push_back({f[x][y], i});
			if(q.front().pos < i - tim)
				q.pop_front();
			f[x][y] = q.front().v + i - q.front().pos;
			ans = max(ans, f[x][y]);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, sx, sy, k;
	cin >> n >> m >> sx >> sy >> k;
	for(int i = 1; i <= n; ++i)
		cin >> (a[i] + 1);
	memset(f, -0x3f, sizeof(f));
	f[sx][sy] = 0;
	for(int s, t, d; k--; ) {
		cin >> s >> t >> d;
		int tim = t - s + 1;
		if(d == 1)
			for(int i = 1; i <= m; ++i)
				DP(n, i, n, tim, d);
		else if(d == 2)
			for(int i = 1; i <= m; ++i)
				DP(1, i, n, tim, d);
		else if(d == 3)
			for(int j = 1; j <= n; ++j)
				DP(j, m, m, tim, d);
		else/* if(d == 4)*/
			for(int j = 1; j <= n; ++j)
				DP(j, 1, m, tim, d);
	}
	cout << ans;
	cout << endl;
	return 0;
}