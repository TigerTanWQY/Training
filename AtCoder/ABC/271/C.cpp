#include <iostream>
using namespace std;

bool vol[300003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, sold = 0;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		if(x >= n + 2 || vol[x])
			++sold;
		else
			vol[x] = true;
	}
	int L = 1, R = n + 1;
	while(true) {
		for(; vol[L]; ++L);
		for(; R && !vol[R]; --R);
		if(sold >= 2) {
			sold -= 2;
			vol[L] = true;
		}
		else {
			if(L >= R)
				break;
			vol[R] = false;
			++sold;
		}
	}
	cout << L - 1;
	return 0;
}
