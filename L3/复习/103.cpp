#include <iostream>
using namespace std;

int f[10000003];

int func(const int& x) {
	if(f[x])
		return f[x];
	if(x == 1)
		return 0;
	return f[x] = func(x / 2) + func(x / 2 + (x & 1)) + x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << func(n) << endl;
	return 0;
}