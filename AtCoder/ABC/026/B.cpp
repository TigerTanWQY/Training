#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const double PI = 3.1415926;
const int N = 1003;
int r[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		cin >> r[i];
	sort(r + 1, r + n + 1, greater<>());
	for(int i = 1; i <= n; ++i)
		if(i & 1)
			ans += r[i] * r[i];
		else
			ans -= r[i] * r[i];
	cout << fixed << setprecision(7) << PI * ans << '\n';
	return 0;
}