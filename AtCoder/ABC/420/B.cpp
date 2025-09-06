#include <bits/stdc++.h>
using namespace std;

string s[102];
int cnt[102];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	for(int j = 0; j < m; ++j) {
		vector<int> a, b;
		for(int i = 0; i < n; ++i)
			if(!(s[i][j] - '0'))
				a.push_back(i);
			else
				b.push_back(i);
		if(a.empty() || b.empty()) {
			for(const auto& x: a)
				++cnt[x];
			for(const auto& x: b)
				++cnt[x];
		} else if(a.size() < b.size())
			for(const auto& x: a)
				++cnt[x];
		else
			for(const auto& x: b)
				++cnt[x];
	}
	int mx = *max_element(cnt, cnt + n);
	for(int i = 0; i < n; ++i)
		if(cnt[i] == mx)
			cout << i + 1 << ' ';
	cout << endl; return 0;
}
