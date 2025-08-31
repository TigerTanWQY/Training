#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e6 + 3;
struct SegTree {
	int T[N << 2];
	#define ls(u) (u << 1)
	#define rs(u) (u << 1 | 1)
	void update(int u)
	{ T[u] = T[ls(u)] + T[rs(u)]; }

	void buildTree(int u, int L, int R) {
		if(L == R) {
			T[u] = 0;
			return;
		}
		int M = (L + R) >> 1;
		buildTree(ls(u), L, M);
		buildTree(rs(u), M + 1, R);
		update(u);
	}

	void mdf(int u, int L, int R, int qL, int qR, int w);
	int qry(int u, int L, int R, int qL, int qR);
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int x1, y1, x2, y2; m--; ) {
		char ch;
		cin >> x1 >> y1 >> x2 >> y2 >> ch;
	}
	cout << endl;
	return 0;
}
