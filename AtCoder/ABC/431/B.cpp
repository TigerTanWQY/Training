#include <bits/stdc++.h>
using namespace std;

bool b[103];
int w[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int X, n, _q;
	cin >> X >> n;
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	cin >> _q;
	for(int p; _q--; cout.put('\n')) {
		cin >> p;
		if(b[p])
			X -= w[p];
		else
			X += w[p];
		b[p] = !b[p];
		cout << X;
	}
	cout.flush(); return 0;
}
