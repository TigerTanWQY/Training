#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	string s;
	cin >> n >> k >> s;
	s += (s.back() - '0'? '0': '1');
	--k;
	vector<pair<int, int>> seg;
	for(int i = 0, j = 1; j <= n; ++j)
		if(s[j] != s[j - 1]) {
			if(s[i] == '1')
				seg.push_back({i, j - 1});
			i = j;
		}
	for(int i = 0; i <= seg[k - 1].second; ++i)
		cout.put(s[i]);
	for(int i = seg[k].first; i <= seg[k].second; ++i)
		cout.put('1');
	for(int i = seg[k - 1].second + 1; i < n; ++i)
		if(!(seg[k].first <= i && i <= seg[k].second))
			cout.put(s[i]);
	cout << endl;
	return 0;
}
