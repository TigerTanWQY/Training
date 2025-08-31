#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> mp;

inline bool err(const string& s) {
	int a[5];
	sscanf(s.c_str(), "%d.%d.%d.%d:%d", a, a+1, a+2, a+3, a+4);
	for(int i = 0; i < 4; ++i)
		if(0 > a[i] || a[i] > 255)
			return true;
	if(0 > a[4] || a[4] > 65535)
		return true;
	char t[23];
	sprintf(t, "%d.%d.%d.%d:%d", a[0], a[1], a[2], a[3], a[4]);
	return string(t) != s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; cout.put('\n'), ++i) {
		string op, ad;
		cin >> op >> ad;
		if(err(ad))
			cout << "ERR";
		else if(op == "Server")
			if(mp.count(ad))
				cout << "FAIL";
			else {
				mp[ad] = i;
				cout << "OK";
			}
		else // op == "Client"
			if(mp.count(ad))
				cout << mp[ad];
			else
				cout << "FAIL";
	}
	cout.flush();
	return 0;
}