#include <bits/stdc++.h>
using namespace std;

string a[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x;
	string name;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> x >> name;
	cout << (a[x] == name? "Yes": "No") << endl;
	return 0;
}
