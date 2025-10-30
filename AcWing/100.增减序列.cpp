#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, lst;
	cin >> n >> lst;
	long long p = 0, q = 0;
	for(int x; --n; lst = x) {
		cin >> x;
		int c = x - lst;
		if(c > 0)
			p += c;
		else
			q -= c;
	}
	cout << max(p, q) << '\n' << abs(p-q) + 1 << endl;
	return 0;
}
