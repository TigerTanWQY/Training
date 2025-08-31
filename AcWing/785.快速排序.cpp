#include <iostream>
#include <algorithm>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}