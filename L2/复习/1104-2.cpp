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
		a.push_front(x);
	}
	for(const auto& x: a)
		cout << x << '\n';
	cout.flush();
	return 0;
}