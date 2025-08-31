#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned long long n;
	cin >> n;
	bool x = 0;
	while(n) {
		if(!(n & 1) && x)
			n = (n >> 1) - 1;
		else
			n >>= 1;
		x = !x;
	}
	if(x)
		cout << "Aoki";
	else
		cout << "Takahashi";
	cout << endl;
	return 0;
}
