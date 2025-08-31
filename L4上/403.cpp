#include <iostream>
using namespace std;

const int N = 200003;
int a[N], s[N], top = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		while(top && a[i] > s[top]) {
			--top;
			++ans;
		}
		ans += !!top;
		s[++top] = a[i];
	}
	cout << ans;
	return .0;
}