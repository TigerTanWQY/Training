#include <iostream>
using namespace std;

int c[103], n;

void ins(int x) {
	for(int i = 2; i * i <= x; ++i)
		for(; x % i == 0; x /= i)
			++c[i];
	if(x > 1)
		++c[x];
}

int f(int x) {
	int res = 0;
	for(int i = 2; i <= n; ++i)
		if(c[i] >= x)
			++res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 2; i <= n; ++i)
		ins(i);
	cout << f(74) + f(24) * (f(2) - 1) + f(14) * (f(4) - 1) + f(4) * (f(4) - 1) * (f(2) - 2) / 2 << endl;
	return 0;
}
