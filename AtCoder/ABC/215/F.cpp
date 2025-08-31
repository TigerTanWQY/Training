#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define _x first
#define _y second

pair<LL, LL> a[200003];
int n;

bool chk(LL d) {
	LL minw = 2e14, maxw = 0;
	for(int i = 1, j = 1; j <= n; ++j) {
		for(; i < j && a[j]._x - a[i]._x >= d; ++i) {
			minw = min(minw, a[i]._y);
			maxw = max(maxw, a[i]._y);
		}
		if(max(maxw - a[j]._y, a[j]._y - minw) >= d)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._x >> a[i]._y;
	sort(a + 1, a + n + 1);
	LL L = 0;
	for(LL R = 2e14; L < R; ) {
		LL M = (L + R + 1) >> 1;
		if(chk(M))
			L = M;
		else
			R = M - 1;
	}
	cout << L << endl;
	return 0;
}
