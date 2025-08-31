#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(6));
	vector<int> s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 6; j++) {
			cin >> a[i][j];
			s.push_back(a[i][j]);
		}
	sort(begin(s), end(s));
	s.erase(unique(begin(s), end(s)), cend(s));
	int k = s.size();
	vector<vector<int>> upd(k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 6; j++) {
			int id = lower_bound(cbegin(s), cend(s), a[i][j]) - cbegin(s);
			upd[id].push_back(i);
		}
	mint ans = 0;
	vector<int> b(n);
	mint prod = 1;
	int zero_cnt = n;
	for(int i = 0; i < k - 1; i++) {
		for (int j: upd[i]) {
			if (!b[j])
				--zero_cnt;
			else
				prod /= b[j];
			++b[j];
			prod *= b[j];
		}
		ans -= (zero_cnt? 0: prod) * (s[i + 1] - s[i]);
	}
	ans /= mint(6).pow(n);
	ans += s[k - 1];
	cout << ans.val() << endl;
	return 0;
}
