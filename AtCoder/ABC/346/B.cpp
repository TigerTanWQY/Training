#include <iostream>
#include <string>
using namespace std;

const string s = "xwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbw";
int c[2][203];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 1; i <= 200; ++i) {
		c[0][i] = c[0][i - 1];
		c[1][i] = c[1][i - 1];
		if(s[i] == 'w')
			++c[0][i];
		else
			++c[1][i];
	}
	int w, b;
	cin >> w >> b;
	for(int i = 1; i <= 200; ++i)
		for(int j = i; j <= 200; ++j)
			if(c[0][j] - c[0][i - 1] == w && c[1][j] - c[1][i - 1] == b) {
				cout << "Yes";
				return 0;
			}
	cout << "No";
	return 0;
}