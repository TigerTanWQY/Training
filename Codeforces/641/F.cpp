#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2003;
int n;
auto rev = [](int x)->int
{ return x > n? (x-n): (x+n); };
struct two_sat {
	bitset<N> G[N];
	int b[N], m;
	bool flg;
	void get(int x) {
		b[x] = 1; b[rev(x)] = 0;
		for(int i = 1; i <= 2 * n; ++i)
			if(G[x][i] && !~b[i])
				get(i);
	}
	void build() {
		for(int i = 1; i <= 2 * n; ++i)
		{ G[i].reset(); G[i][i] = true; b[i] = -1; }
		for(int i = 1, x, y; i <= m; ++i) {
			cin >> x >> y;
			x = x > 0? x: rev(-x);
			y = y > 0? y: rev(-y);
			G[rev(x)][y] = G[rev(y)][x] = true;
		}
		for(int k = 1; k <= 2 * n; ++k)
			for(int i = 1; i <= 2 * n; ++i)
				if(G[i][k])
					G[i] |= G[k];
		for(int i = 1; i <= n; ++i)
			if(G[i][n + i] && G[n + i][i]) {
				flg = false;
				return;
			}
		flg = true;
		for(int i = 1; i <= n; ++i) {
			if(!~b[i] && !~b[n + i] && G[i][n + i])
				get(n + i);
			if(!~b[i] && !~b[n + i] && G[n + i][i])
				get(i);
		}
	}
	void print() {
		for(int i = 1; i <= 2 * n; ++i)
			if(!~b[i])
				get(i);
		for(int i = 1; i <= n; ++i)
			cout << b[i] << ' ';
		cout.put('\n');
	}
} A, B;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> A.m >> B.m;
	A.build(); B.build();
	if(!A.flg && !B.flg) {
		cout << "SIMILAR" << endl;
		return 0;
	} else if(!A.flg || !B.flg) {
		if(A.flg)
			A.print();
		else if(B.flg)
			B.print();
		cout.flush(); return 0;
	}
	for(int i = 1; i <= 2 * n; ++i)
		if(~A.b[i] && ~B.b[i] && A.b[i] != B.b[i])
		{ A.print(); cout.flush(); return 0; }
		else if((!~A.b[i]) ^ (!~B.b[i])) {
			if(!~A.b[i])
			{ A.get(!B.b[i]? i: rev(i)); A.print(); }
			else if(!~B.b[i])
			{ B.get(!A.b[i]? i: rev(i)); B.print(); }
			cout.flush(); return 0;
		}
	for(int i = 1; i <= 2 * n; ++i)
		for(int j = 1; j <= 2 * n; ++j)
			if(A.G[i][j] && !B.G[i][j] && !~B.b[i] && !~B.b[i]) {
				B.get(i); B.get(rev(j)); B.print();
				cout.flush(); return 0;
			} else if(B.G[i][j] && !A.G[i][j] && !~A.b[i] && !~A.b[j]) {
				A.get(i); A.get(rev(j)); A.print();
				cout.flush(); return 0;
			}
	cout << "SIMILAR" << endl;
	return 0;
}
