#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> m;
	vector<int> a;
	for(int i = 10; i >= 0; --i) {
		const int k = pow(3, i);
		while(m >= k) {
			m -= k;
			a.push_back(i);
		}
	}
	cout << a.size() << '\n';
	for(const auto& x: a)
		cout << x << ' ';
	cout << endl;
	return 0;
}