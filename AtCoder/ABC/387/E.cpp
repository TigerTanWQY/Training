#include <bits/stdc++.h>
using namespace std;

bool chk(int x) {
	int tot = 0;
	for(int i = x; i; i /= 10)
		tot += i % 10;
	return x % tot == 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();
	if(n <= 6) {
		n = stoi(s);
		for(int i = n; i < 2 * n; ++i)
			if(chk(i) && chk(i + 1)) {
				cout << i << endl;
				return 0;
			}
		cout << "-1";
	} else if(s[0] == '1')
		if(s[1] == '0')
			cout << "11" + string(n - 2, '0');
		else
			cout << '2' + string(n - 1, '0');
	else if(s[0] > '5')
		cout << "11" + string(n - 1, '0');
	else
		cout << (char) (s[0] + 1) << (char) (103 - s[0]) << string(n - 2, '0');
	cout << endl;
	return 0;
}
