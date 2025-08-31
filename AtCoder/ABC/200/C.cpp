#include <bits/stdc++.h>
using namespace std;

vector<int> mp[200];
int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i] % 200].push_back(i);
	}
	long long ans = 0;
	for(int i = 0; i < 200; ++i)
		if(!mp[i].empty())
			ans += mp[i].size() * (mp[i].size() - 1) / 2;
	cout << ans << endl;
	return 0;
}