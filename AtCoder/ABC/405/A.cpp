#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if(1600 <= n && n < 3000 && k == 1)
		cout << "Yes";
	else if(1200 <= n && n < 2400 && k == 2)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}
