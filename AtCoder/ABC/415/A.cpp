#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, tar;
	cin >> n;
	vector<int> a(n);
	for(auto& x: a)
		cin >> x;
	cin >> tar;
	cout << (count(cbegin(a), cend(a), tar)? "Yes": "No") << endl;
	return 0;
}
