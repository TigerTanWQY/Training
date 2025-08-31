#include <iostream>
#include <string>
#include <bitset>
using namespace std;

constexpr const int N = 103;
bitset<10003> f[N];
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, S;
	cin >> n >> S;
	for(int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	f[0][0] = true;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= S; ++j)
			if(f[i][j]) {
				if(j + a[i] <= S)
					f[i + 1][j + a[i]] = true;
				if(j + b[i] <= S)
					f[i + 1][j + b[i]] = true;
			}
	if(f[n][S]) {
		cout << "Yes\n";
		string t(n, 'H');
		for(int i = n - 1; i >= 0; --i)
			if(S >= a[i] && f[i][S - a[i]]) {
				t[i] = 'H';
				S -= a[i];
			} else {
				t[i] = 'T';
				S -= b[i];
			}
		cout << t;
	} else
		cout << "No";
	cout << endl;
	return 0;
}