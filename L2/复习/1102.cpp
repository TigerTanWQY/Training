#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	list<int> a;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		a.push_back(x);
	}
	auto cit = a.cbegin();
	for(int _ = n / 2; --_; ++cit);
	cout << *cit << endl;
	return 0;
}