#include <iostream>
using namespace std;

char s[3][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> (s[1] + 1) >> (s[2] + 1);
	if((s[1][1] == '#' && s[1][2] == '#') || (s[1][1] == '#' && s[2][1] == '#') || (s[1][2] == '#' && s[2][2] == '#') || (s[2][1] == '#' && s[2][2] == '#'))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}