#include <iostream>
#include <algorithm>
using namespace std;

int a[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if(n == 0) {
		cout.put('0');
		return 0;
	} else if(n < 0) {
		cout.put('-');
		n = -n;
	}
	int k = 0;
	for(; n; n /= 10)
		a[++k] = n % 10;
	int i = 1;
	for(; i <= k && !a[i]; ++i);
	for(; i <= k; ++i)
		cout.put('0' + a[i]);
	cout << endl;
	return 0;
}