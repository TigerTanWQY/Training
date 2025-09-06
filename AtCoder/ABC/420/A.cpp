#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	int res = (x + y) % 12;
	if(!res)
		res = 12;
	cout << res << endl;
	return 0;
}
