#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<int> s;
	long long ans = 0;
	for(int x; n--; ) {
		cin >> x;
		while(!s.empty() && s.top() <= x)
			s.pop();
		ans += s.size();
		s.push(x);
	}
	cout << ans;
	return 0;
}