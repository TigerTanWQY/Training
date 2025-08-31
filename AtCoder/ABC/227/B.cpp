#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	for(int _ = 0, x; _ < n; ++_) {
		cin >> x;
		bool flag = true;
		for(int a = 1; flag && a <= x; ++a)
			for(int b = 1; flag && b <= x; ++b)
				if(4 * a * b + 3 * a + 3 * b == x)
					flag = false;
		if(flag)
			++ans;
	}
	cout << ans;
	return 0;
}