#include <iostream>
#include <string>
using namespace std;

int cnt[33][200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	const int n = s.size();
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 26; ++j)
			cnt[j][i + 1] = cnt[j][i] + (s[i] == 'A' + j);
	long long ans = 0;
	for(int i = 1; i + 1 < n; ++i)
		for(int j = 0; j < 26; ++j)
			ans += (long long)cnt[j][i] * (cnt[j][n] - cnt[j][i + 1]);
	cout << ans << endl;
	return 0;
}