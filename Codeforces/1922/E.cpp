#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(long long n; _T--; cout.put('\n')) {
		cin >> n;
		vector<bool> op;
		for(; n > 1; n >>= 1) {
			op.push_back(n & 1);
			if(n & 1)
				op.push_back(0);
		}
		vector<long long> ans;
		long long L = 1, R = 0;
		for(auto it = crbegin(op); it != crend(op); ++it)
			if(*it)
				ans.push_back(--L);
			else
				ans.push_back(++R);
		cout << ans.size() << '\n';
		for(const auto& x: ans)
			cout << x << ' ';
	}
	cout.flush(); return 0;
}
