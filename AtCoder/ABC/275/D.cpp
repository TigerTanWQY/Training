#include <iostream>
#include <unordered_map>
using namespace std;
using LL = long long;

unordered_map<LL, LL> cnt;

LL f(const LL& x) {
	if(cnt.count(x))
		return cnt[x];
	return cnt[x] = f(x / 2) + f(x / 3);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL n;
	cin >> n;
	++cnt[0];
	cout << f(n);
	return 0;
}