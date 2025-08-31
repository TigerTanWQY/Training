#include <iostream>
#include <string>
using namespace std;

int cnt(const int i) {
	int res = 0;
	string s = to_string(i);
	for(const auto& ch: s)
		if(ch == '2')
			++res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L, R;
	cin >> L >> R;
	int ans = 0;
	for(int i = L; i <= R; ++i)
		ans += cnt(i);
	cout << ans << endl;
	return 0;
}