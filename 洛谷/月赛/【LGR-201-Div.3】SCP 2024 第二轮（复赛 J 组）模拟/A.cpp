#include <iostream>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(LL n, k; _T--; cout.put('\n')) {
		cin >> n >> k;
		if(!k)
			cout.put('1');
		else
			cout << (n / k - n / (k + 1));
	}
	cout.flush();
	return 0;
}