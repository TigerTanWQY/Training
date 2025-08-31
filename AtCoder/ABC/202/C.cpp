#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100003;
unordered_map<int, int> a;
int b[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0, x; i < n; ++i) {
		cin >> x;
		++a[x];
	}
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		if(a.count(b[c[i]]))
			ans += a[b[c[i]]];
	cout << ans;
	cout << endl;
	return 0;
}