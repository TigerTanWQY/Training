#include <bits/stdc++.h>
using namespace std;
using U = unsigned;

constexpr const U N = 1e6 + 3;
char s[N], t[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	U _T;
	cin >> _T;
	for(U n; _T--; cout.put('\n')) {
		cin >> n >> s >> t;
		U m = n >> __builtin_ctz(n); n /= m;
		vector a(n, vector<U>(m)), b(n, vector<U>(m));
		for(U i = 0; i < n * m; ++i) {
			a[i / m][i % m] = s[i] - '0';
			b[i / m][i % m] = t[i] - '0';
		}
		U p = 0;
		for(U i = 0; i < m; ++i) {
			U q = p;
			for(; q < n && !a[q][i]; ++q);
			if(q >= n)
				continue;
			swap(a[p], a[q]);
			for(U j = 0; j < n; ++j)
				if(j != p && a[j][i])
					for(U k = i; k < m; ++k)
						a[j][k] ^= a[p][k];
			++p;
		}
		p = 0;
		for(U i = 0; i < m; ++i) {
			U q = p;
			for(; q < n && !b[q][i]; ++q);
			if(q >= n)
				continue;
			swap(b[p], b[q]);
			for(U j = 0; j < n; ++j)
				if(j != p && b[j][i])
					for(U k = i; k < m; ++k)
						b[j][k] ^= b[p][k];
			++p;
		}
		bool flg = true;
		for(U i = 0; flg && i < n; ++i)
			for(U j = 0; flg && j < m; ++j)
				if(a[i][j] != b[i][j]) {
					cout << "No";
					flg = false;
				}
		if(flg)
			cout << "Yes";
	}
	cout.flush(); return 0;
}
