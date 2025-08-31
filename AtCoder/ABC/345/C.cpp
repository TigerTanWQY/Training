#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	unordered_map<char, int> cnt;
	for(const auto& c: s)
		++cnt[c];
	bool flag = false;
	int n = s.size();
	long long ans = 1LL * n * n;
	for(char c = 'a'; c <= 'z'; ++c) {
		ans -= 1LL * cnt[c] * cnt[c];
		if(cnt[c] > 1)
			flag = true;
	}
	ans /= 2;
	ans += flag;
	cout << ans;
	return 0;
}