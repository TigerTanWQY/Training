#include <iostream>
using namespace std;

int a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i < n; ++i) {
		cout << a[i] << ' ';
		if(a[i] < a[i + 1])
			for(int x = a[i] + 1; x < a[i + 1]; ++x)
				cout << x << ' ';
		else if(a[i] > a[i + 1])
			for(int x = a[i] - 1; x > a[i + 1]; --x)
				cout << x << ' ';
	}
	cout << a[n];
	return 0;
}
