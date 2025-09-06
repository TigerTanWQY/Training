#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& x: a)
		cin >> x;
	sort(begin(a), end(a));
	a.erase(unique(begin(a), end(a)), cend(a));
	cout << a.size() << '\n';
	for(const auto& x: a)
		cout << x << ' ';
	cout << endl;
	return 0;
}
