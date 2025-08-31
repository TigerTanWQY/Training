#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = 0;
	ans += n / 100;
	n %= 100;
	ans += n / 50;
	n %= 50;
	ans += n / 10;
	n %= 10;
	ans += n / 5;
	n %= 5;
	ans += n;
	n = 0;
	cout << ans << endl;
	return 0;
}