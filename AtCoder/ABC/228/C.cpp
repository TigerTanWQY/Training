#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int s[100003], t[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		t[i] = s[i] = a + b + c;
	}
	nth_element(t + 1, t + k, t + n + 1, greater<int>());
	for(int i = 1; i <= n; ++i)
		if(s[i] + 300 >= t[k])
			cout << "Yes\n";
		else
			cout << "No\n";
	return 0;
}