#include <iostream>
using namespace std;

string getmin(string s) {
	int n = s.size();
	s += s;
	int i = 0, j = 1;
	while(j < n) {
		int k = 0;
		while(k + 1 < n && s[i + k] == s[j + k])
			++k;
		(s[i + k] > s[j + k]? i: j) += k + 1;
		if(i == j)
			++j;
		if(i > j)
			swap(i, j);
	}
	return s.substr(i, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s, t;
	cin >> s >> t;
	auto ms = getmin(s), mt = getmin(t);
	if(ms == mt)
		cout << "Yes\n" << ms;
	else
		cout << "No";
	cout << endl; return 0;
}
