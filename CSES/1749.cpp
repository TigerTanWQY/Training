#include <iostream>
using namespace std;

int a[200003], c[200003], n;

auto lb = [](int x) { return x & -x; };

void mdf(int x, int w) {
	for(; x <= n; x += lb(x))
		c[x] += w;
}

int qry(int x) {
	int res = 0;
	for(int i = 17; i >= 0; --i)
		if(res + (1 << i) <= n && c[res + (1 << i)] < x) {
			res += (1 << i);
			x -= c[res];
		}
	return res + 1;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		mdf(i, 1);
	}
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		int res = qry(x);
		cout << a[res] << ' ';
		mdf(res, -1);
	}
	cout << endl; return 0;
}
