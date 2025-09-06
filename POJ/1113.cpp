#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
#define _x first
#define _y second

constexpr const int N = 1e5 + 3;
PII a[N], stk[N];
int n, top = 0;

int cross(const PII& A, const PII& B, const PII& C)
{ return (B._x - A._x) * (C._y - A._y) - (B._y - A._y) * (C._x - A._x); }

int dis(const PII& A, const PII& B)
{ return sqrt((A._x - B._x) * (A._x - B._x) + (A._y - B._y) * (A._y - B._y)); }

int Andrew() {
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		for(; top > 1 && cross(stk[top - 1], stk[top], a[i]) <= 0; --top);
		stk[++top] = a[i];
	}
	int t = top;
	for(int i = n - 1; i; --i) {
		for(; top > t && cross(stk[top - 1], stk[top], a[i]) <= 0; --top);
		stk[++top] = a[i];
	}
	int res = 0;
	for(int i = 1; i < top; ++i)
		res += dis(stk[i], stk[i + 1]);
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._x >> a[i]._y;
	cout << Andrew() << endl;
	return 0;
}
