#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 103, M = 503;
int id[N], w[N], f[N][M][M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int tot = 0;
	for(int i = 0; i < n; ++i) {
		cin >> id[i] >> w[i];
		tot += w[i];
	}
	if(tot % 3) {
		cout << "-1" << endl;
		return 0;
	}
	tot /= 3;
	memset(f, 0x3f, sizeof(f));
	f[0][0][0] = 0;
	for(int i = 0; i < n; ++i)
		for(int tot1 = 0; tot1 <= tot; ++tot1)
			for(int tot2 = 0; tot2 <= tot; ++tot2)
				if(f[i][tot1][tot2] != 0x3f3f3f3f) {
					if(tot1 + w[i] <= tot)
						f[i + 1][tot1 + w[i]][tot2] = min(f[i + 1][tot1 + w[i]][tot2], f[i][tot1][tot2] + (id[i] != 1));
					if(tot2 + w[i] <= tot)
						f[i + 1][tot1][tot2 + w[i]] = min(f[i + 1][tot1][tot2 + w[i]], f[i][tot1][tot2] + (id[i] != 2));
					f[i + 1][tot1][tot2] = min(f[i + 1][tot1][tot2], f[i][tot1][tot2] + (id[i] != 3));
				}
	cout << (f[n][tot][tot] == 0x3f3f3f3f? -1: f[n][tot][tot]) << endl;
	return 0;
}