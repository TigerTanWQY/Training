#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int _ = 0, x; _ < 5; ++_) {
		cin >> x;
		s.insert(x);
	}
	cout << s.size();
	return 0;
}
