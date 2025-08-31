#include <iostream>
#include <string>
using namespace std;

string a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int m; q--; cout.put('\n')) {
		string t;
		cin >> m >> t;
		int res = 0x3f3f3f3f;
		for(int i = 1; i <= n; ++i)
			if(a[i].size() >= m && a[i].substr(a[i].size() - m, m) == t)
				res = min(res, stoi(a[i]));
		if(res == 0x3f3f3f3f)
			res = -1;
		cout << res;
	}
	cout.flush();
	return 0;
}