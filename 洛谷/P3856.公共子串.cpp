#include <iostream>
#include <cstring>
using namespace std;

constexpr const int N = 103, M = 26;
char s[3][N];
int nxt[3][N][M + 3], len[3];
long long f[N][N][N];

long long dfs(const int x, const int y, const int z) {
	if(f[x][y][z])
		return f[x][y][z];
	for(int i = 0; i <= M; ++i)
		if(nxt[0][x][i] && nxt[1][y][i] && nxt[2][z][i]) {
			f[x][y][z] += dfs(nxt[0][x][i], nxt[1][y][i], nxt[2][z][i]);
		}
	if(x || y || z)
		++f[x][y][z];
	return f[x][y][z];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s[0] + 1) >> (s[1] + 1) >> (s[2] + 1);
	len[0] = strlen(s[0] + 1); len[1] = strlen(s[1] + 1); len[2] = strlen(s[2] + 1);
	for(int k = 0; k < 3; ++k)
		for(int i = len[k] - 1; i >= 0; --i) {
			for(int j = 0; j < M; ++j)
				nxt[k][i][j] = nxt[k][i + 1][j];
			nxt[k][i][s[k][i + 1] - 'a'] = i + 1;
		}
	cout << dfs(0, 0, 0) << endl;
	return 0;
}