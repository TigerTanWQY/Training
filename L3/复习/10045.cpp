#include <iostream>
#include <unordered_map>
using namespace std;
using LL = long long;

unordered_map<LL, LL> mp;

LL f(const LL x) {
	if(mp.count(x))
		return mp[x];
	else
		return mp[x] = f(x / 2) + f(x / 3);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n;
	cin >> n;
	mp[0] = 1;
	cout << f(n) << endl;
	return 0;
}