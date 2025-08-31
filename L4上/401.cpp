#include <iostream>
using namespace std;

const int N = 200003;
int a[N], s[N], f[N], top = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		while(s[0] && a[s[s[0]]] < a[i])
			f[s[s[0]--]] = i;
		s[++s[0]] = i;
	}
	for(int i = 1; i <= n; ++i)
		cout << f[i] << ' ';
	return 0;
}