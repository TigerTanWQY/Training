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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int x = 0; x < 1 << n; cout.put('\n'), ++x)
		cout << f(x);
	cout.flush();
	return 0;
}