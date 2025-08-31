#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const int P = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> s;
	s.reserve(1003);
	for(string t; cin >> t; )
		s.push_back(t);
	stack<int> c;
	for(auto cit = s.crbegin(); cit != s.crend(); ++cit) {
		string t = *cit;
		if('0' <= t[0] && t[0] <= '9')
			c.push(stoi(t));
		else {
			int x = c.top();
			c.pop();
			int y = c.top();
			c.pop();
			if(t == "+")
				c.push((x + y) % P);
			else if(t == "-")
				c.push((x - y + P) % P);
			else
				c.push(1LL * x * y % P);
		}
	}
	cout << c.top();
	return 0;
}