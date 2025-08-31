#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 200003;
int c[N];
LL f[2][N], g[2][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	for(int i = 0; i < n; ++i) {
		f[0][i + 1] = f[0][i];
		f[1][i + 1] = f[1][i];
		if(i % 2 == 0)
			f[!(s[i] - '0')][i + 1] += c[i];
		else
			f[s[i] - '0'][i + 1] += c[i];
	}
	for(int i = n - 1; i >= 0; --i) {
		g[0][i] = g[0][i + 1];
		g[1][i] = g[1][i + 1];
		if(i % 2 == 0)
			g[s[i] - '0'][i] += c[i];
		else
			g[!(s[i] - '0')][i] += c[i];
	}
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i < n; ++i)
		ans = min(ans, f[0][i] + g[0][i]);
	for(int i = 1; i < n; ++i)
		ans = min(ans, f[1][i] + g[1][i]);
	cout << ans;
	return 0;
}