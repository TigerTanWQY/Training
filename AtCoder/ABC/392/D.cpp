#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for(int i = 0, k; i < n; ++i) {
		cin >> k;
		a[i].resize(k);
		for(int j = 0; j < k; ++j)
			cin >> a[i][j];
	}
	double maxp = 0.0;
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j) {
			unordered_map<int, int> cnt1, cnt2;
			for(int x: a[i])
				++cnt1[x];
			for(int x: a[j])
				++cnt2[x];
			long long tot = 0;
			for(const auto& [x, cnt]: cnt1)
				if(cnt2.find(x) != cnt2.cend())
					tot += (long long)cnt * cnt2[x];
			double p = 1.0 * tot / (a[i].size() * a[j].size());
			maxp = max(maxp, p);
		}
	cout << fixed << setprecision(10) << maxp << endl;
	return 0;
}
