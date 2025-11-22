#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	vector<pair<char, int>> a;
	for(int i = 0; i < s.size(); ) {
		char ch = s[i]; int st = i;
		for(; i < s.size() && s[i] == ch; ++i);
		a.push_back({ch, i-st});
	}
	long long ans = 0;
	for(int i = 0; i < a.size() - 1; ++i)
		if(a[i+1].first == a[i].first + 1)
			ans += min(a[i].second, a[i+1].second);
	cout << ans << endl;
	return 0;
}
