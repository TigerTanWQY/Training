#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int dxy[2][2]{{1, 0}, {0, 1}};
constexpr const int N = 2003;
char a[N][N];
int n, m, r[N], c[N];
LL f[N][N][3][3];

LL solve() {
	memset(f, 0x3f, sizeof(f));
	for(int i = 0; i < 2; ++i) {
		int j = a[1][1] ^ i;
		f[1][1][0][j] = i * r[1] + j * c[1];
		f[1][1][1][i] = i * r[1] + j * c[1];
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0; k < 2; ++k)
				for(int l = 0; l < 2; ++l) {
					int tx = i + dxy[k][0], ty = j + dxy[k][1];
					if(tx > n || ty > m)
						continue;
					bool flag = a[tx][ty] ^ l;
					int t = 0;
					if(k == 0)
						t = r[tx] * flag;
					else
						t = c[ty] * flag;
					for(int td = 0; td < 2; ++td) {
						int tl = l;
						if(k != td)
							tl = flag;
						f[tx][ty][td][tl] = min(f[tx][ty][td][tl], f[i][j][k][l] + t);
					}
				}
	LL res = 0x3f3f3f3f3f3f3f3f;
	for(int k = 0; k < 2; ++k)
		for(int l = 0; l < 2; ++l)
			res = min(res, f[n][m][k][l]);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> r[i];
	for(int i = 1; i <= m; ++i)
		cin >> c[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			a[i][j] -= '0';
		}
	auto ans = solve();
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			a[i][j] ^= 1;
	ans = min(ans, solve());
	cout << ans << endl;
	return 0;
}