#include <iostream>
#include <map>
using namespace std;

map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0, x; i < n; ++i) {
		cin >> x;
		++mp[x];
	}
	for(auto crit = mp.crbegin(); crit != mp.crend(); ++crit)
		cout << crit->second << '\n';
	for(int i = 0; i < n - mp.size(); ++i)
		cout << "0\n";
	cout.flush();
	return 0;
}