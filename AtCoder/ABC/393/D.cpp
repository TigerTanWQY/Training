#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	vector<int> id;
	for(int i = 0; i < n; ++i)
		if(s[i] == '1')
			id.push_back(i);
	int k = id.size();
	vector<int> f(k);
	for(int i = 0; i < k; ++i)
		f[i] = id[i] - i;
	long long ans = 0;
	for(const auto& x: f)
		ans += abs(x - f[k / 2]);
	cout << ans << endl;
	return 0;
}
