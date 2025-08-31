#include <iostream>
#include <vector>
#include <stack>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	stack<int, vector<int>> stk;
	for(int i = n - 1; i; --i) {
		while(!stk.empty() && a[stk.top()] <= a[i + 1])
			stk.pop();
		stk.push(i + 1);
		f[i] = stk.size();
	}
	for(int i = 1; i <= n; ++i)
		cout << f[i] << ' ';
	cout << endl;
	return 0;
}