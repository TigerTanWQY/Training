#include <iostream>
using namespace std;

int a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i <= n; ++i)
		cin >> a[n - i];
	for(int i = n; i; --i)
		if(a[i]) {
			if(a[i] > 0) {
				if(i != n)
					cout.put('+');
				if(a[i] != 1)
					cout << a[i];
			} else if(a[i] < 0)
				if(a[i] == -1)
					cout.put('-');
				else
					cout << a[i];
			cout.put('x');
			if(i > 1)
				cout << '^' << i;
		}
	if(a[0]) {
		if(a[0] > 0)
			cout.put('+');
		cout << a[0];
	}
	cout << endl;
	return 0;
}