#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	stack<int> s;
	for(string op; m--; ) {
		cin >> op;
		if(op == "push") {
			int x;
			cin >> x;
			s.push(x);
		} else if(op == "pop")
			s.pop();
		else if(op == "empty")
			if(s.empty())
				cout << "YES\n";
			else
				cout << "NO\n";
		else if(op == "query")
			cout << s.top() << '\n';
	}
	return 0;
}