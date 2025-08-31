#include <iostream>
#include <cctype>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, const int> h{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
stack<char> op;
stack<int> num;

void eval() {
	int x = num.top();
	num.pop();
	int y = num.top();
	num.pop();
	char ch = op.top();
	op.pop();
	int res = 0;
	if(ch == '+')
		res = y + x;
	else if(ch == '-')
		res = y - x;
	else if(ch == '*')
		res = y * x;
	else if(ch == '/')
		res = y / x;
	num.push(res);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i)
		if(isdigit(s[i])) {
			int x = 0, j = i;
			for(; j < s.size() && isdigit(s[j]); ++j)
				x = x * 10 + s[j] - '0';
			num.push(x);
			i = j - 1;
		} else if(s[i] == '(')
			op.push(s[i]);
		else if(s[i] == ')') {
			while(op.top() != '(')
				eval();
			op.pop();
		} else {
			while(!op.empty() && h[op.top()] >= h[s[i]])
				eval();
			op.push(s[i]);
		}
	while(!op.empty())
		eval();
	cout << num.top();
	return 0;
}