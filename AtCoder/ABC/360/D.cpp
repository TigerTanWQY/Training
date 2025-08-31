#include <iostream>
//#include <cmath>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
#define int long long

const int N = 200003;
pair<int, char> a[N];
int x[N], cnt[2][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	string s;
	cin >> n >> t >> s;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
/*
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(x[i] < x[j]) {
				if(s[i - 1] == '1' && s[j - 1] == '0' && x[j] - x[i] <= 2 * t)
					++ans;
			}
			else
				if(s[i - 1] == '0' && s[j - 1] == '1' && x[i] - x[j] <= 2 * t)
					++ans;
	cout << ans;
*/
	for(int i = 1; i <= n; ++i)
		a[i] = {x[i], s[i - 1]};
	sort(a + 1, a + n + 1);
	for(int i = n; i; --i) {
		cnt[0][i] = cnt[0][i + 1];
		cnt[1][i] = cnt[1][i + 1];
		if(a[i].second - '0')
			++cnt[1][i];
		else
			++cnt[0][i];
	}
/*
	for(int i = 1; i <= n; ++i)
		cout << cnt[0][i] << ' ' << cnt[1][i] << '\n';
	cout << '\n';
*/
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i].second - '0')
			ans += cnt[0][i] - cnt[0][upper_bound(a + 1, a + n + 1, make_pair(a[i].first + 2 * t, '0')) - a];
	cout << ans;
	cout << endl;
	return 0;
}