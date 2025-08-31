#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	for(int c = 1; c < s.size(); ++c)
		for(int w = c; w < s.size(); ++w) {
			string r;
			for(int i = 1; (i - 1) * w + c - 1 < s.size(); ++i)
				r += s[(i - 1) * w + c - 1];
			if(r == t) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	cout << "No";
	cout << endl;
	return 0;
}