#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	string s;
	cin >> n >> d >> s;
	for(int i = n - 1; ~i; --i)
		if(!d)
			break;
		else if(s[i] == '@') {
			s[i] = '.';
			--d;
		}
	cout << s << endl;
	return 0;
}
