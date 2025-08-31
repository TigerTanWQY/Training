#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string n;
	cin >> n;
	if(n.size() == 1) {
		if(n == "8")
			cout << "Yes";
		else
			cout << "No";
		return 0;
	} else if(n.size() == 2) {
		if(stoi(n) % 8 == 0)
			cout << "Yes";
		else {
			swap(n[0], n[1]);
			if(stoi(n) % 8 == 0)
				cout << "Yes";
			else
				cout << "No";
		}
		return 0;
	}
	vector<int> cnt(10);
	for(const char& c: n)
		++cnt[c - '0'];
	for(int i = 112; i < 1000; i += 8) {
		auto c = cnt;
		for(const char& x: to_string(i))
			--c[x - '0'];
		bool flag = true;
		for(int j = 0; flag && j < 10; ++j)
			if(c[j] < 0)
				flag = false;
		if(flag) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}