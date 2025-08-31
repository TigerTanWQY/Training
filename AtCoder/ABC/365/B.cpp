#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	cout << a[n - 1].second;
	cout.flush();
	return 0;
}