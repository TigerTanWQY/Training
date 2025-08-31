#include <iostream>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int x; q--; cout.put('\n')) {
		cin >> x;
		if(*lower_bound(a + 1, a + n + 1, x) == x)
			cout << "Yes";
		else
			cout << "No";
	}
	cout.flush();
	return 0;
}