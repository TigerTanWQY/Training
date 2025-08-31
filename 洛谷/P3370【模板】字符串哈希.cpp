#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ULL = unsigned long long;

const int BASE = 383;
string str[10003];
ULL h[10003];

ULL Hash(const string& s) {
	ULL ret = 0, base = 1;
	for(const auto& p: s) {
		ret = ret * base + p;
		base *= BASE;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> str[i];
		h[i] = Hash(str[i]);
	}
	sort(h + 1, h + n + 1);
	for(int i = 1; i <= n; ++i)
		if(h[i] != h[i - 1])
			++ans;
	cout << ans;
	return 0;
}