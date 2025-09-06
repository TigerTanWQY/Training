#include <iostream>
#include <cstring>
using namespace std;

const int N = 1003;
bool c[N][N];
int n;

int lb(int x)
{ return x & -x; }

void mdf(int x, int y) {
	for(; x <= n; x += lb(x))
		for(int j = y; j <= n; j += lb(j))
			c[x][j] ^= true;
}

bool qry(int x, int y) {
	bool res = false;
	for(; x; x -= lb(x))
		for(int j = y; j; j -= lb(j))
			res ^= c[x][j];
	return res;
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int _q; _T--; cout.put('\n')) {
		cin >> n >> _q;
		for(char op; _q--; ) {
			cin >> op;
			if(op == 'C') {
				int x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				mdf(x1, y1); mdf(x2 + 1, y2 + 1);
				mdf(x1, y2 + 1); mdf(x2 + 1, y1);
			} else {
				int x, y;
				cin >> x >> y;
				cout << qry(x, y) << '\n';
			}
		}
		memset(c, 0, sizeof(c));
	}
	cout.flush();
	return 0;
}
