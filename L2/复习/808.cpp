#include <iostream>
#include <stack>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	stack<int> stk;
	for(int i = 1, j = 1; i <= n && j <= n; ++j) {
		stk.push(j);
		cout << "push " << j << '\n';
		while(!stk.empty() && stk.top() == a[i]) {
			stk.pop();
			cout << "pop\n";
			++i;
		}
	}
	for(; !stk.empty(); stk.pop())
		cout << "pop\n";
	cout.flush();
	return 0;
}