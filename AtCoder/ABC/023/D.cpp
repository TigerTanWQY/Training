#include <bits/stdc++.h>
using namespace std;
#define _x first
#define _y second

constexpr const int N = 1e5 + 3;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._x >> a[i]._y;
	cout << endl;
	return 0;
}
