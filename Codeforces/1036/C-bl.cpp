#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
using LL = long long;

vector<LL> a;

bool check(LL x) {
	unordered_multiset<int> s;
	for(; x; x /= 10)
		if(x % 10)
			s.insert(x % 10);
	return s.size() <= 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 1; i <= 1e8; ++i)
		if(check(i))
			a.push_back(i);
//	int T;
//	cin >> T;
//	for(LL L, R, cnt = 0; T--; cnt = 0) {
//		cin >> L >> R;
//		for(auto cit = lower_bound(a.cbegin(), a.cend(), L); cit != a.cend(); cit = upper_bound(a.cbegin(), a.cend(), *cit))
//			if(*cit <= R)
//				++cnt;
//			else
//				break;
//		cout << cnt << '\n';
//	}
	for(const auto& x: a)
		cout << x << ' ';
	cout << flush;
	return 0;
}