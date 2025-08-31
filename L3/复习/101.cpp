#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = 1;
	for(; n; --n)
		ans *= n;
	cout << ans << endl;
	return 0;
}