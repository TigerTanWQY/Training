#include <iostream>
using namespace std;

int a[10003], mp[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= m; ++i)
		mp[i] = i;
	int t = 1;
	for(int j = m + 1; ; ++t) {
		for(int i = 1; i <= m; ++i)
			if(a[mp[i]] > 0) {
				--a[mp[i]];
				if(a[mp[i]] == 0 && j <= n)
					mp[i] = j++;
			}
		bool flag = true;
		for(int i = 1; flag && i <= n; ++i)
			if(a[mp[i]])
				flag = false;
		if(flag)
			break;
	}
	cout << t << endl;
	return 0;
}