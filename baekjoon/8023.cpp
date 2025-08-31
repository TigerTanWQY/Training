#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

constexpr const int N = 1'003;
bitset<25'003> f[N];
int w[N], g[N][25'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	f[1][w[1]] = true;
//	g[1][w[1]] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= 25'000; ++j)
			if(f[i][j]) {
				f[i + 1][j] = true;
				g[i + 1][j] = max(g[i + 1][j], g[i][j]);
				f[i + 1][j + w[i + 1]] = true;
				g[i + 1][j + w[i + 1]] = max(g[i + 1][j + w[i + 1]], g[i][j]);
				f[i + 1][abs(j - w[i + 1])] = true;
				g[i + 1][abs(j - w[i + 1])] = max(g[i + 1][abs(j - w[i + 1])], min(g[i][j] + w[i + 1], g[i][j] + j));
			}
	cout << g[n][0] << endl;
	return 0;
}
/*
// http://yq5jjvr7drkjrelzhut7kgclfuro65jjlivyzfmxiq2kyv5lickrl4qd.onion/bridges/?transport=webtunnel&ipv6=yes
bridges:
webtunnel [2001:db8:dce7:5c62:a9d2:e3ce:4ec4:90da]:443 B38D147145A772CC7CB54F26052A54585F89B0CE url=https://nextsync.space/ailootaepoyiShao0aep ver=0.0.1

*/