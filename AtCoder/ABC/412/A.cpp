#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	for(int x, y; n--; ) {
		cin >> x >> y;
		if(y > x)
			++ans;
	}
	cout << ans << endl;
	return 0;
}
