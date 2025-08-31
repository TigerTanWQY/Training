#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	string s;
	cin >> n >> d >> s;
	cout << n - count(cbegin(s), cend(s), '@') + d << endl;
	return 0;
}
