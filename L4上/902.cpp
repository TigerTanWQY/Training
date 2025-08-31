#include <iostream>
#include <atcoder/dsu>
using namespace std;
using atcoder::dsu;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	dsu G(n + 1);
	for(int x, y; m--; ) {
		cin >> x >> y;
		G.merge(x, y);
	}
	cout << G.groups().size() - 2;
	return 0;
}