#include <iostream>
using namespace std;

int a[500003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long x = 0, y = 0;
	for(int i = 1; i <= n; ++i)
		if(i == a[i])
			++x;
		else if(a[a[i]] == i)
			++y;
	cout << x * (x - 1) / 2 + y / 2 << endl;
	return 0;
}