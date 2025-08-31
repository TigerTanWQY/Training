#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, L, R;
	cin >> n >> L >> R;
	if(L / n == R / n)
		cout << R % n;
	else
		cout << n - 1;
	cout << endl;
	return 0;
}