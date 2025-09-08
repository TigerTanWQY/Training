#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
int idx[N], sp[N], al[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, _q;
	cin >> n >> _q;
	for(int i = 1; i <= n; ++i)
		idx[i] = sp[i] = al[i] = i;
	for(int op, a, b; _q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> a >> b;
			idx[a] = sp[b];
		} else if(op == 2) {
			cin >> a >> b;
			int ta = sp[a], tb = sp[b];
			swap(sp[a], sp[b]);
			al[ta] = b;
			al[tb] = a;
		} else {
			cin >> a;
			cout << al[idx[a]] << '\n';
		}
	}
	cout.flush();
	return 0;
}
