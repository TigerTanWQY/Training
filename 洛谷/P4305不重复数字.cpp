#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int n; T--; ) {
		cin >> n;
		unordered_set<int> s;
		vector<int> ans;
		s.reserve(50003);
		for(int i = 1, x; i <= n; ++i) {
			cin >> x;
			if(!s.count(x)) {
				s.insert(x);
				ans.push_back(x);
			}
		}
		for(const auto& x: ans)
			cout << x << ' ';
		cout << '\n';
	}
	return 0;
}