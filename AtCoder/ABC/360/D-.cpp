#include <iostream>
using namespace std;
typedef long long LL;

LL func(const LL& x, const int& k)
{ return x / k + x / 10 - x / (k * 10); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(LL L, R; n--; ) {
		cin >> L >> R;
		cout << func(R, k) - func(L - 1, k) << '\n';
	}
	return 0;
}