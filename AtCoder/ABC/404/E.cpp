#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2003;
int c[N], a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i)
		cin >> c[i];
	for(int i = 1; i < n; ++i)
		cin >> a[i];
	int res = 0, pre = 0;
	for(int i = 1; i < n; ++i)
		if(a[i]) {
			int L = i, R = i;
			while(pre < L) {
				++res;
				int nL = L;
				for(int j = L; j <= R; ++j)
					nL = min(nL, j - c[j]);
				L = nL;
			}
			pre = i;
		}
	cout << res << endl;
	return 0;
}
