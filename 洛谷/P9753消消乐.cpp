#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
#define id second

constexpr const int N = 2e6 + 3, P = 191;
unordered_map<ULL, int> mp;
stack<pair<char, int>> stk;
char s[N];
ULL hsh[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n >> s;
	for(int i = n; i; --i)
		swap(s[i], s[i-1]);
	long long ans = 0;
	mp[0] = 1;
	stk.emplace(0, 0);
	for(int i = 1; i <= n; ++i)
		if(stk.size() == 1) {
			stk.emplace(s[i], i);
			hsh[i] = s[i] - '0';
			ans += mp[hsh[i]]++;
		} else if(stk.top().first == s[i]) {
			stk.pop();
			hsh[i] = hsh[stk.top().id];
			ans += mp[hsh[i]]++;
		} else {
			hsh[i] = hsh[stk.top().id] * P + (s[i] - '0');
			stk.emplace(s[i], i);
			ans += mp[hsh[i]]++;
		}
	cout << ans << endl;
	return 0;
}
