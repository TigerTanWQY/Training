#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

__gnu_pbds::gp_hash_table<string, int> mp;
vector<string> ans;
string s;
int n, m;

void _chg(int i, int w) {
	if(!(0 <= i && i + 2 < n && s[i] != s[i + 1] && s[i + 1] == s[i + 2]))
		return;
	string t = s.substr(i, 3);
	mp[t] += w;
	if(mp[t] >= m)
		ans.push_back(t);
}

void chg(int i, int w) {
	_chg(i - 2, w);
	_chg(i - 1, w);
	_chg(i, w);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> s;
	for(int i = 0; i < n; ++i)
		_chg(i, 1);
	for(int i = 0; i < n; ++i) {
		char tmp = s[i];
		for(char ch = 'a'; ch <= 'z'; ++ch) {
			chg(i, -1);
			s[i] = ch;
			chg(i, 1);
		}
		chg(i, -1);
		s[i] = tmp;
		chg(i, 1);
	}
	sort(begin(ans), end(ans));
	ans.erase(unique(begin(ans), end(ans)), cend(ans));
	(cout << ans.size()).put('\n');
	for(const auto& p: ans)
		(cout << p).put('\n');
	cout.flush();
	return 0;
}
