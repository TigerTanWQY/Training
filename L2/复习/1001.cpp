#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}