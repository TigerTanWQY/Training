#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int a, b, c; _T--; cout.put('\n')) {
		cin >> a >> b >> c;
		cout << min({a, c, (int) ((0LL+a+b+c)/3)});
	}
	cout.flush(); return 0;
}
