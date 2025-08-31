#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using PDD = pair<double, double>;
#define _x first
#define _y second

constexpr const int N = 1e5 + 3;
PII a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	PDD Ma, Mb;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i]._x >> a[i]._y;
		Ma._x += a[i]._x;
		Ma._y += a[i]._y;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> b[i]._x >> b[i]._y;
		Mb._x += b[i]._x;
		Mb._y += b[i]._y;
	}
	Ma._x /= n; Ma._y /= n; Mb._x /= n; Mb._y /= n;
	auto dis = [](const PDD& A, const PDD& B) -> double
	{ return sqrt((A._x - B._x) * (A._x - B._x) + (A._y - B._y) * (A._y - B._y)); };
	sort(a + 1, a + n + 1, [&dis, &Ma, &Mb](const PII& A, const PII& B) -> bool
		{ return dis(A, Ma) > dis(B, Ma); });
	sort(b + 1, b + n + 1, [&dis, &Ma, &Mb](const PII& A, const PII& B) -> bool
		{ return dis(A, Mb) > dis(B, Mb); });
	cout << fixed << setprecision(8) << dis(b[1], Mb) / dis(a[1], Ma) << endl;
	return 0;
}
