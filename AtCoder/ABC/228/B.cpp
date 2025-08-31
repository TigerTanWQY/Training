#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = x; ; i = a[i]) {
		if(s.count(i))
			break;
		s.insert(i);
	}
	cout << s.size();
	return 0;
}