#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int a[200003], n;
LL m;

bool check(const LL& x) {
	LL tot = 0;
	for(int i = 1; i <= n; ++i)
		tot += min(x, (LL)a[i]);
	return tot <= m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	LL tot = m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot -= a[i];
	}
	if(tot >= 0) {
		cout << "infinite";
		return 0;
	}
	LL L = 0, R = 2e14 + 1;
	while(L + 1 < R) {
		LL M = (L + R) / 2;
		if(check(M))
			L = M;
		else
			R = M;
	}
	cout << L;
	cout.flush();
	return 0;
}