#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int n, ans; cin >> n && n; ) {
		cin >> ans;
		for(int x; --n; ) {
			cin >> x;
			ans ^= x;
		}
		if(ans)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	cout.flush();
	return 0;
}