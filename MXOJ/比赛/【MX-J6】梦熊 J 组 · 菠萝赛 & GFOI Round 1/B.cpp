#include <iostream>
using namespace std;

long long f(long long n, int d) {
	if(d & 1)
		return (n + 1) / 2 * (n / 2 + 1);
	else
		return n * (n + 1) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, k, d; _T--; ) {
		cin >> n >> k >> d;
		cout << f(n, d) << '\n';
	}
	cout.flush();
	return 0;
}