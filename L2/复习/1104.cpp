#include <iostream>
using namespace std;

int a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = n; i; --i)
		cout << a[i] << '\n';
	cout.flush();
	return 0;
}