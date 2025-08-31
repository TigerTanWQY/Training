#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int odd = 0, one = 0;
	for(int _ = 0, x; _ < n; ++_) {
		cin >> x;
		if(x & 1)
			++odd;
		if(x == 1)
			++one;
	}
	if(one != n)
		++odd;
	if((odd + n) & 1)
		cout << "Alice";
	else
		cout << "Bob";
	cout.flush();
	return 0;
}