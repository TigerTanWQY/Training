#include <iostream>
#include <stack>
using namespace std;

const int N = 200003;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<int> s;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		while(!s.empty() && a[s.top()] < a[i]) {
			f[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for(int i = 1; i <= n; ++i)
		cout << f[i] << ' ';
	return 0;
}