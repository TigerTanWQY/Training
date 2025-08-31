#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
using LL = long long;

vector<LL> a;

bool check(LL x) {
	unordered_multiset<int> s;
	s.reserve(11);
	for(; x; x /= 10)
		if(x % 10)
			s.insert(x % 10);
	return s.size() <= 3;
}

void dfs(const int& cnt, const int& tot, const LL& x) {
	if(cnt > 3 || tot > 18)
		return;
	if(x && check(x))
		a.push_back(x);
	if(x)
		dfs(cnt, tot + 1, x * 10);
	for(int i = 1; i < 10; ++i)
		dfs(cnt + 1, tot + 1, x * 10 + i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	dfs(0, 0, 0);
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.cend());
	a.push_back(1e18);
	int T;
	cin >> T;
	for(LL L, R; T--; ) {
		cin >> L >> R;
		cout << upper_bound(a.cbegin(), a.cend(), R) - lower_bound(a.cbegin(), a.cend(), L) << '\n';
	}
	return 0;
}