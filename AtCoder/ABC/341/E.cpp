#include <iostream>
#include <string>
#include <atcoder/segtree>
using namespace std;
using atcoder::segtree;

int op(const int x, const int y)
{ return x + y; }
int init()
{ return 0; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	string s;
	cin >> n >> q >> s;
	segtree<int, op, init> seg(n + 1);
	for(int i = 0; i < n - 1; ++i)
		if(s[i] != s[i + 1])
			seg.set(i + 1, 1);
	for(int x, L, R; q--; ) {
		cin >> x >> L >> R;
		if(x == 1) {
			seg.set(L - 1, 1 - seg.get(L - 1));
			seg.set(R, 1 - seg.get(R));
		} else {
			if(seg.prod(L, R) == R - L)
				cout << "Yes";
			else
				cout << "No";
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}