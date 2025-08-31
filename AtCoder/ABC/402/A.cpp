#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	for(const auto& ch: s)
		if(isupper(ch))
			cout.put(ch);
	cout << endl; return 0;
}
