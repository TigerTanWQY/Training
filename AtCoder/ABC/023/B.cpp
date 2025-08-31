#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	deque<char> a{'b'};
	if(n == 1 && s == "b") {
		cout << "0\n";
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		if(i % 3 == 1) {
			a.push_front('a');
			a.push_back('c');
		} else if(i % 3 == 2) {
			a.push_front('c');
			a.push_back('a');
		} else {
			a.push_front('b');
			a.push_back('b');
		}
		if(a.size() == n) {
			bool flag = true;
			for(int j = 0; flag && j < n; ++j)
				if(s[j] != a[j])
					flag = false;
			if(flag)
				cout << i << '\n';
			else
				cout << "-1\n";
			break;
		} else if(a.size() > n) {
			cout << "-1\n";
			break;
		}
	}
	return 0;
}