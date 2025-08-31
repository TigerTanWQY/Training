#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300003;
int a[N], s1[N], top1 = 0, s2[N], top2 = 0, f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		while(top1 && a[s1[top1]] <= a[i])
			--top1;
		s1[++top1] = i;
		while(top2 && a[s2[top2]] > a[i])
			--top2;
		s2[++top2] = i;
		f[i] = f[*lower_bound(s2 + 1, s2 + top2 + 1, s1[top1 - 1]) - 1] + 1;
	}
	cout << f[n];
	return 0;
}