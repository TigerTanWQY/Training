#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	stack<char> stk;
	for(const auto& ch: s)
		if(ch == '(' || ch == '[')
			stk.push(ch);
		else if(ch == ')')
			if(stk.top() == '(')
				stk.pop();
			else {
				cout << "No" << endl;
				return 0;
			}
		else if(ch == ']')
			if(stk.top() == '[')
				stk.pop();
			else {
				cout << "No" << endl;
				return 0;
			}
	if(stk.empty())
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}