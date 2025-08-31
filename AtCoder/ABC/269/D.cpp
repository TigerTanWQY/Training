#include <iostream>
using namespace std;

const int N = 1003;
const int d[2][7]{{114, -1, -1, 0, 0, 1, 1}, {514, -1, 0, -1, 1, 0, 1}};
int B[N][N];

void dfs(const int& x, const int& y) {
	--B[x][y];
	for(int j = 6; j; --j) {
		int tx = x + d[0][j], ty = y + d[1][j];
		if(B[tx][ty])
			dfs(tx, ty);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(cin >> a; cin >> a >> b; )
		++B[a + 1001][b + 1001];
	int ans = 0;
	for(int y = 1; y < 2002; ++y) {
		for(int x = 1; x < 2002; ++x)
		if(B[x][y]) {
			++ans;
			dfs(x, y);
		}
	}
	cout << ans;
	return 0;
}