#include <iostream>
#include <string>
using namespace std;

constexpr const int N = 100'003;
int a[N], len[N], f[N];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m >> s;
	int cnt = 0, k = 0, maxl = 0;
	for(int i = 0; i < m; ++i)
		if(i <= m - 3 && s.substr(i, 3) == "abc") {
			++k;
			i += 2;
		} else if(k) {
			len[++cnt] = k;
			k = 0;
			maxl = max(maxl, len[cnt]);
		}
	if(k) {
		len[++cnt] = k;
		maxl = max(maxl, len[cnt]);
	}
	for(int i = 1; i <= maxl; ++i)
		for(int j = max(i - n, 0); j < i; ++j)
			f[i] = max(f[i], f[j] + a[i - j]);
	long long ans = 0;
	for(int i = 1; i <= cnt; ++i)
		ans += f[len[i]];
	cout << ans;
	cout.flush();
	return 0;
}