#include <iostream>
#include <stack>
using namespace std;
using LL = long long;
#define _L first
#define _R second

constexpr const int N = 1e7 + 3;
pair<int, int> tree[N];
int a[N], n;

void build() {
	stack<int> stk;
	for(int i = 1; i <= n; ++i)
		tree[i]._L = tree[i]._R = 0;
	for(int i = 1; i <= n; ++i) {
		int lst = 0;
		while(!stk.empty() && a[stk.top()] > a[i]) {
			lst = stk.top();
			stk.pop();
		}
		if(!stk.empty())
			tree[stk.top()]._R = i;
		tree[i]._L = lst;
		stk.push(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	build();
	LL ansL = 0, ansR = 0;
	for(int i = 1; i <= n; ++i) {
		ansL ^= (LL)i * (tree[i]._L + 1);
		ansR ^= (LL)i * (tree[i]._R + 1);
	}
	cout << ansL << ' ' << ansR << endl;
	return 0;
}