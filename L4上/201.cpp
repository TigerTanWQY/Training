#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, tot = 0;
	cin >> n >> m;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s.insert(x);
	}
	for(int i = 1, x; i <= m; ++i) {
		cin >> x;
		if(s.count(x))
			++tot;
	}
	if(tot * 2 >= m)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}