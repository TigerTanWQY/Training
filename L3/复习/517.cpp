#include <iostream>
#include <cstring>
using namespace std;

int f[2][33];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	f[0][1] = 1;
	for(f[0][1] = 1; m--; memcpy(f[0], f[1], sizeof(int) * (n + 1)))
		for(int i = 1; i <= n; ++i)
			f[1][i] = f[0][i == 1? n: i - 1] + f[0][i == n? 1: i + 1];
	cout << f[0][1] << endl;
	return 0;
}