#include <iostream>
#include <stack>
using namespace std;

constexpr const int N = 2e5 + 3;
struct Node
{ int L, R, val; }
tree[N];
int a[N], n;

void build() {
	stack<int> stk;
	int rt = 0;
	for(int i = 1; i <= n; ++i) {
		tree[i].L = tree[i].R = 0;
		tree[i].val = a[i];
	}
	for(int i = 1; i <= n; ++i) {
		int lst = 0;
		while(!stk.empty() && a[stk.top()] > a[i]) {
			lst = stk.top();
			stk.pop();
		}
		if(!stk.empty())
			tree[stk.top()].R = i;
		else
			rt = i;
		tree[i].L = lst;
		stk.push(i);
	}
	// root => rt
	cout << rt << '\n';
	for(int i = 1; i <= n; ++i)
		cout << i << ' ' << tree[i].val << ' ' << tree[i].L << ' ' << tree[i].R << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	build();
	cout.flush();
	return 0;
}