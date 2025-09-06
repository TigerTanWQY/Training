#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> _q;
	bool login = false; int ans = 0;
	for(string op; _q--; ) {
		cin >> op;
		if(op == "login")
			login = true;
		else if(op == "logout")
			login = false;
		else if(op == "private")
			if(!login)
				++ans;
	}
	cout << ans << endl; return 0;
}
