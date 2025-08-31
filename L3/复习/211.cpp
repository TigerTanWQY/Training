#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const int P = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> a;
	a.reserve(1003);
	for(string t; cin >> t; a.push_back(t));
	stack<int> s;
	for(auto cit = a.cbegin(); cit != a.cend(); ++cit) {
		string t = *cit;
		if('0' <= t[0] && t[0] <= '9')
			s.push(stoi(t));
		else {
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			if(t == "+")
				s.push((y + x) % P);
			else if(t == "-")
				s.push((y - x + P) % P);
			else
				s.push(1LL * y * x % P);
		}
	}
	cout << s.top();
	return 0;
}