#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	if(n & 1) {
		for(int _ = n / 2; _--; )
			cout.put('-');
		cout.put('=');
		for(int _ = n / 2; _--; )
			cout.put('-');
	} else {
		for(int _ = n / 2; --_; )
			cout.put('-');
		cout << "==";
		for(int _ = n / 2; --_; )
			cout.put('-');
	}
	cout << endl;
	return 0;
}
