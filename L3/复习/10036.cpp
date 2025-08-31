#include <iostream>
#include <bitset>
using namespace std;

constexpr const int N = 3e5 + 2;
bitset<N> vol;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] >= n + 2)
			++cnt;
		else if(vol[a[i]])
			++cnt;
		else
			vol[a[i]] = true;
	}
	int L = 1, R = n + 1;
	while(true) {
		while(vol[L])
			++L;
		while(R != 0 && !vol[R])
			--R;
		if(cnt >= 2) {
			cnt -= 2;
			vol[L] = true;
		} else {
			if(L >= R)
				break;
			vol[R] = false;
			++cnt;
		}
	}
	cout << L - 1 << endl;
	return 0;
}