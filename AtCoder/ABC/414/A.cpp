#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, L, R;
	cin >> n >> L >> R;
	int ans = 0;
	for(int x, y; n--; ) {
		cin >> x >> y;
		if(x <= L && y >= R)
			++ans;
	}
	cout << ans << endl;
	return 0;
}
