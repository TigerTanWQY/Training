#include <iostream>
#include <utility>
using namespace std;
#define _x first
#define _y second

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(pair<int, int> a, b; _T--; ) {
		cin >> a._x >> a._y >> b._x >> b._y;
		int ans = 0;
		if(a._x > b._x && a._y > b._y)
			++ans;
		swap(a._x, a._y);
		if(a._x > b._x && a._y > b._y)
			++ans;
		swap(a._x, a._y);
		swap(b._x, b._y);
		if(a._x > b._x && a._y > b._y)
			++ans;
		swap(b._x, b._y);
		swap(a._x, a._y);
		swap(b._x, b._y);
		if(a._x > b._x && a._y > b._y)
			++ans;
		swap(a._x, a._y);
		swap(b._x, b._y);
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}