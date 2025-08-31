#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int getmin() {
	s += s;
	int i = 0, j = 1;
	while(j < n) {
		int k = 0;
		for(; k + 1 < n && s[i + k] == s[j + k]; ++k);
		(s[i + k] > s[j + k]? i: j) += k + 1;
		if(i == j)
			++j;
		if(i > j)
			swap(i, j);
	}
	return i;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(string t; cin >> t; s += t);
	cout << getmin() << endl;
	return 0;
}
