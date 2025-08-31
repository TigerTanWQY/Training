#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<string> ans;
	for(int i = 0; i < n; ++i) {
		char ch = s[i];
		for(s[i] = 'a'; s[i] <= 'z'; ++s[i])
			for(int j = 1; j + 1 < n; ++j)
				if(s[j - 1] != s[j] && s[j] == s[j + 1]) {
					auto t = s.substr(j - 1, 3);
					int cnt = 0;
					for(auto l = s.find(t); l != string::npos; l = s.find(t, l + 1))
						++cnt;
					if(cnt >= k)
						ans.push_back(t);
				}
		s[i] = ch;
	}
	sort(begin(ans), end(ans));
	ans.erase(unique(begin(ans), end(ans)), cend(ans));
	cout << ans.size() << '\n';
	for(const auto& t: ans)
		cout << t << '\n';
	cout.flush();
	return 0;
}
