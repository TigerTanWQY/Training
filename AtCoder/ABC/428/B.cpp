#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k; string s;
	cin >> n >> k >> s;
	unordered_map<string, int> cnt;
	for(int i = 0; i <= n - k; ++i)
		++cnt[s.substr(i, k)];
	vector<string> ans; int mx = 0;
	for(const auto& [t, w]: cnt)
		if(w > mx) {
			mx = w;
			ans = {t};
		} else if(w == mx)
			ans.push_back(t);
	sort(begin(ans), end(ans));
	cout << mx << '\n';
	for(const auto& t: ans)
		cout << t << ' ';
	cout << endl; return 0;
}
