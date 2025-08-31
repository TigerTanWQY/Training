#include <iostream>
using namespace std;

pair<int, int> a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].second >> a[i].first;
	cin >> q;
	for(int i, date; q--; cout.put('\n')) {
		cin >> i >> date;
		cout << date + (a[i].first - date % a[i].second + a[i].second) % a[i].second;
	}
	cout.flush();
	return 0;
}