#include <iostream>
#include <cstring>
using namespace std;

constexpr const int P = 1e9 + 7;
int f[200'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	for(int i = 0; i <= n; ++i)
		if(i <= c)
			f[i] = 1;
		else
			f[i] = ((i - a >= 0? f[i - a]: 1) + (i - b >= 0? f[i - b]: 1)) % P;
	cout << f[n];
	cout.flush();
	return 0;
}