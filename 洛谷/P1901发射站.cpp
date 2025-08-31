#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 1000003;
int h[N], v[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> h[i] >> v[i];
	stack<int> s;
	for(int i = 1; i <= n; ++i) {
		while(!s.empty() && h[i] > h[s.top()]) {
			f[i] += v[s.top()];
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	for(int i = n; i; --i) {
		while(!s.empty() && h[i] > h[s.top()]) {
			f[i] += v[s.top()];
			s.pop();
		}
		s.push(i);
	}
	cout << *max_element(f + 1, f + n + 1);
	return 0;
}