#include <iostream>
#include <string>
using namespace std;

constexpr const char s[][12] {
	"QWERTYUIOP",
	"ASDFGHJKL",
	"ZXCVBNM"
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char ch;
	cin >> ch;
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 10; ++j)
			if(s[i][j] == ch) {
				cout << i + 1 << ' ' << j + 1 << endl;
				return 0;
			}
	return 0;
}