#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	int ans = 1;
	for(int y, tot = 0; n--; ) {
		cin >> y;
		tot += y;
		if(tot <= x)
			++ans;
	}
	cout << ans;
	return 0;
}