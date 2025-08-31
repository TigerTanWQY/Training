#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char s[4];
	cin >> s[0] >> s[1] >> s[2];
	int a[3]{0, 1, 2};
	do {
		if(((a[0] < a[1] && s[0] == '<') || (a[0] > a[1] && s[0] == '>'))
			&& ((a[0] < a[2] && s[1] == '<') || (a[0] > a[2] && s[1] == '>'))
			&& ((a[1] < a[2] && s[2] == '<') || (a[1] > a[2] && s[2] == '>')))
				for(int i = 0; i < 3; ++i)
					if(a[i] == 1) {
						cout << (char) ('A' + i) << endl;
						return 0;
					}
	} while(next_permutation(a, a + 3));
	return 0;
}