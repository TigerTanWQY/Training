#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e6 + 3;
int a[N], ans[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	stack<int> stk;
	for(int i = n; i; --i) {
		for(; !stk.empty() && a[i] >= a[stk.top()]; stk.pop());
		ans[i] = (stk.empty()? 0: stk.top());
		stk.push(i);
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl; return 0;
}
