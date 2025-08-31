#include <iostream>
using namespace std;

const int N = 103;
bool G[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int u = 1, x; u <= n; ++u)
		for(int v = 1; v <= n; ++v) {
			cin >> x;
			G[u][v] = x;
		}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				G[i][j] |= (G[i][k] & G[k][j]);
	for(int u = 1; u <= n; ++u) {
		for(int v = 1; v <= n; ++v)
			cout << G[u][v] << ' ';
		cout << '\n';
	}
	return 0;
}