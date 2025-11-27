#include <bits/stdc++.h>
using namespace std;
#define _L first
#define _R second

constexpr const int N = 1e7 + 3;
pair<int, int> T[N];
int a[N], n;

void build() {
	stack<int> stk;
	for(int i = 1; i <= n; ++i) {
		for(; !stk.empty() && a[stk.top()] > a[i]; stk.pop())
			T[i]._L = stk.top();
		if(!stk.empty())
			T[stk.top()]._R = i;
		stk.push(i);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	build();
	long long ansL = 0, ansR = 0;
	for(int i = 1; i <= n; ++i) {
//		cerr.put('\n');
		ansL ^= 1LL * i * (T[i]._L + 1);
		ansR ^= 1LL * i * (T[i]._R + 1);
	}
	cout << ansL << ' ' << ansR << endl;
	return 0;
}
