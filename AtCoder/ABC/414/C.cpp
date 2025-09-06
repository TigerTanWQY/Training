#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool is_pal(const string &s) {
	for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
		if(s[i] != s[j])
			return false;
	return true;
}

bool next_cur(vector<int> &cur, int A) {
	const int n = cur.size();
	for(int i = n - 1; i >= 0; --i) {
		++cur[i];
		if(cur[i] < A)
			return true;
		cur[i] = 0;
	}
	return false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL LA, n;
	cin >> LA >> n;
	int A = (int)LA;
	if(n < 1) {
		cout.put('0') << endl;
		return 0;
	}
	LL base = 1; int maxd = 1;
	while(base <= n / A) {
		++maxd;
		base *= A;
	}
	LL ans = 0;
	for(int d = 1; d <= maxd; ++d) {
		int M = (d + 1) / 2;
		vector<int> cur(M, 0);
		cur[0] = 1;
		while(true) {
			vector<int> a(d, 0);
			if(d % 2 == 0)
				for(int i = 0; i < M; ++i)
					a[i] = a[d - 1 - i] = cur[i];
			else {
				for(int i = 0; i < M; ++i)
					a[i] = cur[i];
				for(int i = 0; i < M - 1; ++i)
					a[d - 1 - i] = cur[i];
			}
			LL tot = 0;
			for(int i = 0; i < d; ++i) {
				if(tot > n / A) {
					tot = n + 1;
					break;
				}
				tot = tot * A + a[i];
			}
			if(tot > n)
				break;
			string s = to_string(tot);
			if(is_pal(s))
				ans += tot;
			if(!next_cur(cur, A))
				break;
		}
	}
	cout << ans << endl;
	return 0;
}
