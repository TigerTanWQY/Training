#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

pair<int, int> a[1003], b[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].first;
			a[i].second = i;
		}
		for(int i = 1; i <= n; ++i) {
			cin >> b[i].first;
			b[i].second = i;
		}
		sort(a + 1, a + n + 1, greater<>());
		sort(b + 1, b + n + 1);
		bool flag = true;
		int tot = 0;
		for(int i = 1; flag && i <= n; ++i) {
			tot += a[i].first;
			tot -= b[i].first;
			if(tot < 0)
				flag = false;
		}
		if(flag) {
			cout << "Yes\n";
			for(int i = 1; i <= n; ++i)
				cout << a[i].second << ' ';
			cout << '\n';
			for(int i = 1; i <= n; ++i)
				cout << b[i].second << ' ';
			cout << '\n';
		} else
			cout << "No\n";
	}
	return 0;
}