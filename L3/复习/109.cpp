#include <iostream>
#include <algorithm>
using namespace std;

int n;

string f(int x) {
	string res;
	int cnt = 0;
	for(; x; ++cnt, x >>= 1)
		res += '0' + (x & 1);
	for(int _ = n - cnt; _; --_)
		res += '0';
	reverse(res.begin(), res.end());
	return res;
}

bool check(const string& s) {
	int cnt0 = 0, cnt1 = 0;
	for(const auto& ch: s)
		if(ch == '0')
			++cnt0;
		else
			++cnt1;
	return cnt0 == cnt1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int x = 0; x < 1 << n; ++x) {
		string tmp = f(x);
		if(check(tmp))
			cout << tmp << '\n';
	}
	cout.flush();
	return 0;
}