#include <iostream>
#include <bitset>
using namespace std;

bitset<63> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long k;
	cin >> k;
	int n = 0;
	for(; k; k >>= 1)
		a[++n] = (k & 1);
	for(int i = 1, j = n; i < j; ++i, --j) {
		bool t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	for(int i = 1; i <= n; ++i)
		if(a[i])
			cout << '2';
		else
			cout << '0';
	return 0;
}
