#include <iostream>
using namespace std;

const int N = 1027;
int c[N][N], n;

int lb(int x)
{ return x & -x; }

void mdf(int x, int y, int w) {
	for(int i = x; i <= n; i += lb(i))
		for(int j = y; j <= n; j += lb(j))
			c[i][j] += w;
}

int qry(int x, int y) {
	int res = 0;
	for(int i = x; i; i -= lb(i))
		for(int j = y; j; j -= lb(j))
			res += c[i][j];
	return res;
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> n >> n;
	for(int op, x, y, w, x1, y1, x2, y2; cin >> op && op != 3; )
		if(op == 1) {
			cin >> x >> y >> w;
			mdf(x + 1, y + 1, w);
		} else {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << qry(x2 + 1, y2 + 1) - qry(x2 + 1, y1) - qry(x1, y2 + 1) + qry(x1, y1) << '\n';
		}
	cout.flush(); return 0;
}
