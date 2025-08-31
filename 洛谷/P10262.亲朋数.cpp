#include <iostream>
#include <string>
using namespace std;

constexpr const int N = 131;
long long f[N], g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int p;
	string s;
	cin >> p >> s;
	long long ans = 0;
	for(const auto& ch: s) {
		int x = (ch - '0') % p;
		for(int j = 0; j < p; ++j)
			f[j] = 0;
		for(int j = 0; j < p; ++j)
			f[(j * 10 + x) % p] += g[j];
		++f[x];
		for(int j = 0; j < p; ++j)
			g[j] = f[j];
		ans += f[0];
	}
	cout << ans << endl;
	return 0;
}