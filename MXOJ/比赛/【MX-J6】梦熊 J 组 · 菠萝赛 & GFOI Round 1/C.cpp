#include <iostream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using LL = long long;

auto f(LL x) {
	unordered_set<LL> st;
	unordered_map<LL, int> cnt;
	for(LL i = 2; i * i <= x; ++i)
		if(x % i == 0) {
			st.insert(i);
			while(x % i == 0) {
				++cnt[i];
				x /= i;
			}
		}
	if(x > 1) {
		st.insert(x);
		++cnt[x];
	}
	return make_pair(st, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(LL n, m; _T--; cout.put('\n')) {
		cin >> n >> m;
		auto fn = f(n), fm = f(m);
		if(fn.first != fm.first)
			cout << "-1";
		else {
			LL ans = 0;
			for(const auto& x: fn.first)
				ans = max(ans, (LL)ceil(log2(1.0 * fm.second[x] / fn.second[x])));
			cout << ans;
		}
	}
	cout.flush();
	return 0;
}