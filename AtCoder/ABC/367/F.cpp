#include <iostream>
#include <random>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

constexpr const int N = 200'003;
int a[N], b[N], id[N];
mint sa[N], sb[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	random_device rd;
	mt19937_64 seed(rd());
	int n, q;
	cin >> n >> q;
	uniform_int_distribution<> dis(0, 1000000006);
	for(int i = 1; i <= n; ++i)
		id[i] = dis(seed);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sa[i] = sa[i - 1] + id[a[i]];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
		sb[i] = sb[i - 1] + id[b[i]];
	}
	for(int La, Ra, Lb, Rb; q--; cout << '\n') {
		cin >> La >> Ra >> Lb >> Rb;
		if(sa[Ra] - sa[La - 1] == sb[Rb] - sb[Lb - 1])
			cout << "Yes";
		else
			cout << "No";
	}
	cout.flush();
	return 0;
}