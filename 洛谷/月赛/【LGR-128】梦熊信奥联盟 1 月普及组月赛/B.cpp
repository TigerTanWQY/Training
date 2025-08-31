#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, _Q;
	cin >> n >> _Q;
	multiset<int> s;
	for(int x; n--; ) {
		cin >> x;
		s.insert(x);
	}
	for(int op, x; _Q--; ) {
		cin >> op >> x;
		if(op == 1) {
			auto cit = s.find(x);
			if(cit == s.cend()) {
				cout << "-1\n";
				continue;
			} else
				s.erase(cit);
		} else
			s.insert(x);
		cout << (*(--s.cend()) - *s.cbegin()) * 2 << '\n';
	}
	cout.flush();
	return 0;
}