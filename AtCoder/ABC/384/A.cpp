#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	char c1, c2;
	string s;
	cin >> n >> c1 >> c2 >> s;
	for(const auto& ch: s)
		if(ch != c1)
			cout.put(c2);
		else
			cout.put(c1);
	cout << endl;
	return 0;
}
