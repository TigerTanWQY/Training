#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

LL f[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL n, m, tot = 0;
	cin >> n >> m;
	map<int, int> cnt;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		++cnt[x];
		tot += x;
	}
	vector<pair<int, int>> a;
	for(const auto& idx: cnt)
		a.push_back(idx);
	int k = a.size();
	if(k == m) {
		cout << '0';
		return 0;
	}
	int idx = k;
	for(int i = 0; i < k; ++i)
		if(a[(i + 1) % k].first != (a[i].first + 1) % m) {
			idx = i;
			break;
		}
	for(int i = 0, j; i < k; ++i) {
		f[j = (idx - i + k) % k] = tot;
		if(a[(j + 1) % k].first == (a[j].first + 1) % m)
			f[j] = f[(j + 1) % k];
		f[j] -= 1LL * a[j].first * a[j].second;
	}
	LL ans = tot;
	for(int i = 0; i < k; ++i)
		ans = min(ans, f[i]);
	cout << ans;
	return 0;
}