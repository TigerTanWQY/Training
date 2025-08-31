#include <iostream>
#include <atcoder/dsu>
using namespace std;
using atcoder::dsu;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	dsu a(n + 1);
	for(char op; m--; ) {
		int x, y;
		cin >> op >> x >> y;
		if(op == 'M')
			a.merge(x, y);
		else
			cout << a.same(x, y) << '\n';
	}
	return 0;
}