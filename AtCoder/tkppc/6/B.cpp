#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; string s, t;
	cin >> n >> s >> t;
	vector<int> p, q;
	for(int i = 0; i < s.size(); ++i) {
		if(i & 1) {
			s[i] = 'A' + (s[i] == 'A');
			t[i] = 'A' + (t[i] == 'A');
		}
		if(s[i] == 'A')
			p.push_back(i);
		if(t[i] == 'A')
			q.push_back(i);
	}
	if(p.size() != q.size()) {
		cout << "-1" << endl;
		return 0;
	}
	long long ans = 0;
	for(int i = 0; i < p.size(); ++i)
		ans += abs(p[i] - q[i]);
	cout << ans << endl;
	return 0;
}
