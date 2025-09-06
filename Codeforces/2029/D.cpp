#include <bits/stdc++.h>
using namespace std;

bool b[200003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m; _T--; ) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			b[i] = 0;
		vector<int> A;
		for(int i = 1, u, v; i <= m; ++i) {
			cin >> u >> v;
			if(u != 1 && v != 1) {
				A.push_back(1);
				A.push_back(u);
				A.push_back(v);
			}
			b[u] ^= 1; b[v] ^= 1;
		}
		int p = 0;
		for(int i = 2; i <= n; ++i)
			if(b[i])
			{ p = i; break; }
		if(p)
			for(int i = 2; i <= n; ++i)
				if(!b[i]) {
					A.push_back(1);
					A.push_back(p);
					A.push_back(i);
					p = i;
				}
		cout << A.size() / 3 << '\n';
		for(int i = 0; i < A.size(); ++i) {
			cout << A[i] << ' ';
			if(i % 3 == 2)
				cout.put('\n');
		}
	}
	return 0;
}
