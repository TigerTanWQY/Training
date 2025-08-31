#include <iostream>
#include <algorithm>
using namespace std;

struct Seg {
	int L, R;
	bool operator<(const Seg& x) const {
		if(R != x.R)
			return R < x.R;
		else
			return L < x.L;
	}
} a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].L >> a[i].R;
	sort(a + 1, a + n + 1);
	int ans = 1;
	for(int i = 2, j = 1; i <= n; ++i)
		if(a[i].L > a[j].R) {
			++ans;
			j = i;
		}
	cout << ans << endl;
	return 0;
}