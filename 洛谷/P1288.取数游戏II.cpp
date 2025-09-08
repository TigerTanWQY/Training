#include <bits/stdc++.h>
using namespace std;

int a[23];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		if(a[i] == 0) {
			if(i % 2 == 0) {
				cout << "YES" << endl;
				return 0;
			}
			break;
		}
	for(int i = n; i; --i)
		if(a[i] == 0) {
			if((n - i + 1) % 2 == 0) {
				cout << "YES" << endl;
				return 0;
			}
			break;
		}
	cout << "NO" << endl;
	return 0;
}
