#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200003;
int a[N], s[N], top = 0, L[N], R[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		while(top && a[i] < a[s[top]])
			--top;
		if(top)
			L[i] = s[top];
		s[++top] = i;
	}
	top = 0;
	for(int i = n; i; --i) {
		while(top && a[i] <= a[s[top]])
			--top;
		if(top)
			R[i] = s[top];
		else
			R[i] = n + 1;
		s[++top] = i;
	}
	for(int i = 1; i <= n; ++i)
		ans = max(ans, 1LL * a[i] * (R[i] - L[i] - 1));
	cout << ans;
	return 0;
}