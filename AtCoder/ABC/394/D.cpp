#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	stack<char> stk;
	for(const auto& ch: s)
		if(ch == '(' || ch == '[' || ch == '<')
			stk.push(ch);
		else if(ch == ')')
			if(!stk.empty() && stk.top() == '(')
				stk.pop();
			else {
				cout << "No" << endl;
				return 0;
			}
		else if(ch == ']')
			if(!stk.empty() && stk.top() == '[')
				stk.pop();
			else {
				cout << "No" << endl;
				return 0;
			}
		else if(ch == '>')
			if(!stk.empty() && stk.top() == '<')
				stk.pop();
			else {
				cout << "No" << endl;
				return 0;
			}
	cout << (stk.empty()? "Yes": "No") << endl;
	return 0;
}
