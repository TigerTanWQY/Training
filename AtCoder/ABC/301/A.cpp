#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	int t = 0, a = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'T')
			++t;
		else
			++a;
	if (t > a)
		cout << 'T' << endl;
	else if (t < a)
		cout << 'A' << endl;
	else
		cout << char('T' + 'A' - s.back()) << endl;
	return 0;
}
