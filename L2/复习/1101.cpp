#include <iostream>
#include <algorithm>
using namespace std;

int a[83];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}