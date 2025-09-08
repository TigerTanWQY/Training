#include <iostream>
#include <algorithm>
using namespace std;

string a[53];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n, [](const string& A, const string& B)
		{ return (A.size() != B.size()? A.size() < B.size(): A < B); });
	for(int i = 0; i < n; ++i)
		cout << a[i];
	cout << endl;
	return 0;
}
