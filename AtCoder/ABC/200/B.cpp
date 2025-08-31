#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	int k;
	cin >> n >> k;
	while(k--)
		if(n % 200)
			n = n * 1000 + 200;
		else
			n /= 200;
	cout << n << endl;
	return 0;
}