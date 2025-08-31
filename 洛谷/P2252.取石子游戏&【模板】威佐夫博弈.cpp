#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, m;
	cin >> n >> m;
	if(n < m)
		swap(n, m);
	if(m == (int) ((sqrtl(5) + 1) / 2 * (n - m)))
		cout.put('0');
	else
		cout.put('1');
	cout << endl;
	return 0;
}