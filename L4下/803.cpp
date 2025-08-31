#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	cin >> n >> ans;
	for(int x; --n; ) {
		cin >> x;
		ans ^= x;
	}
	if(ans)
		cout << "Alice";
	else
		cout << "Bob";
	cout.flush();
	return 0;
}