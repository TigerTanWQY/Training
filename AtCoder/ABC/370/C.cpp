#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Data {
	int i;
	char ch1, ch2; // s[i], t[i]
	bool operator<(const Data x) const {
		if(ch1 > ch2 && x.ch1 < x.ch2)
			return true;
		else if(ch1 < ch2 && x.ch1 > x.ch2)
			return false;
		else if(ch1 > ch2)
			return i < x.i;
		else
			return i > x.i;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s, t;
	cin >> s >> t;
	int n = s.size();
	vector<Data> op;
	for(int i = 0; i < n; ++i)
		if(s[i] != t[i]) {
			Data tmp;
			tmp.i = i; tmp.ch1 = s[i]; tmp.ch2 = t[i];
			op.push_back(tmp);
		}
	sort(op.begin(), op.end());
	cout << op.size() << '\n';
	for(const auto& p: op) {
		s[p.i] = t[p.i];
		cout << s << '\n';
//		cout << p.i << ' ' << (int)p.ch1 << ' ' << (int)p.ch2 << '\n';
	}
	cout.flush();
	return 0;
}