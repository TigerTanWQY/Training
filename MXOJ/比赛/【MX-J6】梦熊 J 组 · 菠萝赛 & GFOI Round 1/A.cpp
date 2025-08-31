#include <iostream>
using namespace std;

int a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(a[i] - a[j] == k) {
				cout << "Yes" << endl;
				return 0;
			}
	cout << "No" << endl;
	return 0;
}