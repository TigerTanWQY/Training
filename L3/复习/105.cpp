#include <iostream>
using namespace std;

string f[18];

inline string rvs(string s) {
	for(auto& ch: s)
		if(ch == 'a')
			ch = 'b';
		else
			ch = 'a';
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	f[1] = "a";
	for(int i = 2; i <= n; ++i)
		f[i] = f[i - 1] + rvs(f[i - 1]);
	cout << f[n] << endl;
	return 0;
}