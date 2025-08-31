#include <iostream>
#include <stack>
using namespace std;

const int N = 1000003;
int f[N];
unsigned long long a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	cin >> n;
	stack<int> s;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		while(!s.empty() && a[s.top()] < a[i]) {
			f[s.top()] = i;
			ans ^= s.top();
			s.pop();
		}
		s.push(i);
		if(!f[i])
			ans ^= i;
		cout << ans << '\n';
	}
	return 0;
}