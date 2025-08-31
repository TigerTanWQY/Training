#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e9 + 7;
bitset<10000003> b;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int L, R;
	cin >> L >> R;
	int k = 0;
	for(int i = L; i <= R; ++i)
		if(!b[i]) {
			++k;
			for(int j = i * 2; j <= R; j += i)
				b[j] = true;
		}
	long long ans = k;
	for(int i = 1; i <= R - L + 2; ++i)
		if(i != k + 1)
			ans = ans * i % P;
	cout << ans << endl;
	return 0;
}
