#include <iostream>
#include <algorithm>
using namespace std;

int a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	prev_permutation(a, a + n);
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}