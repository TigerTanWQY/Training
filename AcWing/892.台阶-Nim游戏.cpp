#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans;
	cin >> n >> ans;
	for(int i = 2, x; i <= n; ++i) {
		cin >> x;
		if(i & 1)
			ans ^= x;
	}
	if(ans)
		cout << "Yes";
	else
		cout << "No";
	cout.flush();
	return 0;
}