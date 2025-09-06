#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> p;
int n, m;

bool chk(int x) {
	vector<bool> b(m);
	bool flg = false;
	for(int i = 0; i < n; ++i) {
		int cnt = 0;
		for(int j = 0; j < m; ++j)
			if(p[i][j] >= x) {
				b[j] = true;
				++cnt;
			}
		if(cnt > 1)
			flg = true;
	}
	if(!flg && m > 1)
		return false;
	return count(cbegin(b), cend(b), true) == m;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(; _T--; cout.put('\n')) {
		cin >> n >> m;
		p.assign(n, vector<int>(m));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				cin >> p[i][j];
		int L = 1, R = 2;
		for(; chk(R); R <<= 1);
		while(L + 1 < R) {
			int M = (R + L) >> 1;
			if(chk(M))
				L = M;
			else
				R = M;
		}
		cout << L;
	}
	cout.flush(); return 0;
}
