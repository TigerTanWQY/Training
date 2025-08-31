#include <iostream>
using namespace std;

int r;

void dfs(int n) {
	if(n == 0)
		return;
	int m = n % r;
	if(m < 0) {
		m -= r;
		n += r;
	}
	if(m >= 10)
		m = 'A' + m - 10;
	else
		m += '0';
	dfs(n / r);
	cout.put(m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> r;
	cout << n << '=';
	dfs(n);
	cout << "(base" << r << ')' << endl;
	return 0;
}