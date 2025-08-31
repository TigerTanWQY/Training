#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int dxy[][4]{{0, -1, 1, 0}, {-1, 0, 0, 1}};
constexpr const int N = 2'003;
LL a[N][N], f[N][N][5];

bool check(const int st, const int dir, const int ed) { // checked OK
	if(st == 0)
		if(dir == 0)
			return ed == 0;
		else if(dir == 1)
			return ed == 0 || ed == 2;
		else if(dir == 2)
			return ed == 0 || ed == 1;
		else
			return true;
	else if(st == 1)
		if(dir == 0)
			return ed == 0 || ed == 1;
		else if(dir == 1)
			return true;
		else if(dir == 2)
			return ed == 1;
		else
			return ed == 1 || ed == 3;
	else if(st == 2)
		if(dir == 0)
			return ed == 0 || ed == 2;
		else if(dir == 1)
			return ed == 2;
		else if(dir == 2)
			return true;
		else
			return ed == 2 || ed == 3;
	else
		if(dir == 0)
			return true;
		else if(dir == 1)
			return ed == 2 || ed == 3;
		else if(dir == 2)
			return ed == 1 || ed == 3;
		else
			return ed == 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	bool sub4 = true;
	LL tot = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			tot += a[i][j];
			if(a[i][j] < 0)
				sub4 = false;
		}
	if(sub4) {
		cout << tot * 4 << endl;
		return 0;
	}
	memset(f, -0x3f, sizeof(f));
	for(int k = 0; k < 4; ++k)
		f[1][1][k] = a[1][1] * (k + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0; k < 4; ++k)
				if(f[i][j][k] != -0x3f3f3f3f3f3f3f3f)
					for(int x = 2; x < 4; ++x) {
						int tx = i + dxy[0][x], ty = j + dxy[1][x];
						if(1 <= tx && tx <= n && 1 <= ty && ty <= m)
							for(int L = 0; L < 4; ++L)
								if(check(k, x, L))
									f[tx][ty][L] = max(f[tx][ty][L], f[i][j][k] + a[tx][ty] * (L + 1));
					}
	cout << max({f[n][m][0], f[n][m][1], f[n][m][2], f[n][m][3]}) << endl;
	return 0;
}